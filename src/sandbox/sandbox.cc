#include "base_value.hh"
#include "sandbox/sandbox.hh"
#include "utils/config.hh"
#include "utils/file.hh"

#include <vector>
#include <thread>

#include <cstring>

#include <fcntl.h>
#include <sched.h>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>

#include <sys/wait.h>

namespace astraea {
namespace libra {
namespace sandbox {

namespace fs = std::filesystem;

/////////////// sandbox private class ///////////////
// namespace {
struct SandboxApply final {
  Sandbox* sandbox;
  const char* input;
  const char* output;
  const char* const out_file;
  const char* const err_file;
  std::string code_file;

  ////////// in container //////////
 public:
  void apply_in_container(SandboxType type) {
    chdir(sandbox->mount_point_.get_merged_dir().c_str());
    sethostname(sandbox->id_.c_str(), sandbox->id_.size());
    switch (type) {
      case SandboxType::COMPILE: {
        break;
      }
      case SandboxType::RUN: {
        if (input != nullptr && std::strcmp(input, "") != 0) {
          freopen(input, "r", stdin);
        }
        sandbox->seccomp_.apply();
        break;
      }
    }
    freopen(out_file, "w", stdout);
    freopen(err_file, "w", stderr);
    sem_wait(sandbox->sem_);
  }
  ////////// out container //////////
 public:
  void apply_out_container(pid_t pid, SandboxType type) {
    // sandbox->namespaces_.user(pid);
    sandbox->cgroup_.set_pid(pid);
    switch (type) {
      case SandboxType::COMPILE: {
        count_resources(pid, type,
                        sandbox->submit.limits.compilation_time,
                        sandbox->submit.limits.compilation_output * 1024);
        if (sandbox->result.judgement_type !=
            astraea::thrift::mq::JudgementType::NONE) {
          sandbox->result.judgement_type =
              astraea::thrift::mq::JudgementType::CE;
        }
        break;
      }
      case SandboxType::RUN: {
        count_resources(pid, type,
                        sandbox->submit.limits.time *
                        sandbox->submit.limits.time_multiplier,
                        sandbox->submit.limits.output * 1024);
        break;
      }
    }
  }
 private:
  void check(int stat, SandboxType type,
             const fs::path& out_file, const fs::path& err_file) {
    if (stat != 0) {
      auto size = fs::file_size(err_file);
      std::string message(size, '\0');
      utils::File f{err_file};
      f.read(const_cast<char*>(message.c_str()), size);
      sandbox->result.judgement_type = astraea::thrift::mq::JudgementType::RTE;
      sandbox->result.message = message;
      return;
    }
    if (type == SandboxType::RUN) {
      std::string system = std::string("diff") + " " + out_file.c_str() + " " + output;
      sandbox->result.judgement_type = std::system(system.c_str()) == 0
          ? astraea::thrift::mq::JudgementType::AC
          : astraea::thrift::mq::JudgementType::WA;
    }
  }
  void count_resources(pid_t pid, SandboxType type,
                       const std::size_t& timeout_value,
                       const std::size_t& output_limit) {
    using namespace std::literals::chrono_literals;
    using clock = std::chrono::steady_clock;
    using time_point = std::chrono::time_point<clock>;
    static const std::chrono::milliseconds duration = 5ms;
    std::chrono::milliseconds timeout = timeout_value * 1ms;
    fs::path proc_status =
        astraea::libra::ROOT / "proc" / std::to_string(pid) / "stat";
    char buffer[1025] = {0};
    int fd, stat;
    fs::path cur = sandbox->mount_point_.get_merged_dir();
    fs::path out_file = sandbox->mount_point_.get_upper_dir() / this->out_file;
    fs::path err_file = sandbox->mount_point_.get_upper_dir() / this->err_file;
    while (fs::exists(out_file) == false || fs::exists(err_file) == false) {
      continue;
    }
    fs::current_path(cur);
    sem_post(sandbox->sem_);
    time_point now = clock::now(), it = now;
    for (time_point end = now + timeout; it < end; it = clock::now()) {
      fd = open(proc_status.c_str(), O_RDONLY);
      read(fd, buffer, 1023);
      close(fd);
      if (buffer[std::strrchr(buffer, ')') - buffer + 2] > 'W') {
        waitpid(pid, &stat, 0);
        return check(stat, type, out_file, err_file);
      }
      if (output_limit - fs::file_size(out_file) < fs::file_size(err_file)) {
        sandbox->result.judgement_type =
            astraea::thrift::mq::JudgementType::RTE;
        kill(pid, SIGKILL);
        waitpid(pid, &stat, 0);
        return;
      }
      std::this_thread::sleep_for(duration);
    }
    sandbox->result.judgement_type = astraea::thrift::mq::JudgementType::TLE;
    kill(pid, SIGKILL);
    waitpid(pid, &stat, 0);
  }
};

/////////////// sandbox private variable ///////////////
namespace {
constexpr std::size_t STACK_SIZE = 4 * 1024 * 1024; // 4 MiB
constexpr unsigned long MASKED = SIGCHLD |
    CLONE_NEWNS | CLONE_NEWUTS | // CLONE_NEWUSER |
    CLONE_NEWIPC | CLONE_NEWPID | CLONE_NEWNET;
}

/////////////// sandbox private function ///////////////
namespace {
int __clone_compile(void* sandbox_ptr) {
  SandboxApply* sandbox = static_cast<SandboxApply*>(sandbox_ptr);
  sandbox->apply_in_container(SandboxType::COMPILE);
  execl("/bin/sh", "sh", "compile.sh", sandbox->code_file.c_str(), nullptr);
  return 0;
}
int __clone_run(void* sandbox_ptr) {
  SandboxApply* sandbox = static_cast<SandboxApply*>(sandbox_ptr);
  sandbox->apply_in_container(SandboxType::RUN);
  execl("/bin/sh", "sh", "run.sh", sandbox->code_file.c_str(), nullptr);
  return 0;
}

std::vector<std::pair<std::string, std::string>>
__get_problem_files(const std::string& submission_id) {
  std::vector<std::pair<std::string, std::string>> ret;
  fs::path problem_ans =
      astraea::libra::utils::Config::problem_ans() / submission_id;
  std::string prev_extension;
  for (auto& p : fs::directory_iterator(problem_ans)) {
    fs::path filename_path = p.path().filename();
    std::string filename = filename_path.string();
    std::string extension = filename_path.extension().string();
    if (extension == ".out") {
      filename = filename.substr(0, filename.size() - extension.size());
      ret.emplace_back(
          prev_extension == "" ? "" : filename + prev_extension,
          filename + extension);
    } else {
      prev_extension = extension;
    }
  }
  return ret;
}
}

/////////////// sandbox implement ///////////////
Sandbox::Sandbox(const std::string& id)
    : id_(id), cgroup_(id), mount_point_(id) {
  this->sem_ = sem_open((id + "1").c_str(), O_CREAT, 0666, 0);
}

void Sandbox::run() {
  SandboxApply sandbox{
    .sandbox = this,
    .out_file = "stdout.txt",
    .err_file = "stderr.txt",
    .code_file = std::string("Main") + "." + this->submit.extensions.front(),
  };
  this->mount_point_.mount(this->submit, sandbox.code_file);
  auto stack = std::make_unique<unsigned char[]>(STACK_SIZE);
  if (this->__compile(&sandbox, stack.get())) {
    this->__run(&sandbox, stack.get());
  }
  this->__clean();
}

bool Sandbox::__compile(SandboxApply* sandbox, unsigned char* stack) {
  this->cgroup_.set_resources(this->submit.limits.compilation_memory *
                              this->submit.limits.mem_multiplier * 1024);
  pid_t pid = clone(__clone_compile, stack + STACK_SIZE,
                    MASKED, reinterpret_cast<void*>(sandbox));
  sandbox->apply_out_container(pid, SandboxType::COMPILE);
  return this->result.judgement_type != astraea::thrift::mq::JudgementType::CE;
}

void Sandbox::__run(SandboxApply* sandbox, unsigned char* stack) {
  this->cgroup_.set_resources(this->submit.limits.memory *
                              this->submit.limits.mem_multiplier * 1024);
  for (const auto& f : __get_problem_files(this->submit.problem)) {
    sandbox->input = f.first.c_str();
    sandbox->output = f.second.c_str();
    pid_t pid = clone(__clone_run, stack + STACK_SIZE,
                      MASKED, reinterpret_cast<void*>(sandbox));
    sandbox->apply_out_container(pid, SandboxType::RUN);
    if (this->result.judgement_type != astraea::thrift::mq::JudgementType::AC) {
      return;
    }
  }
}

void Sandbox::__clean() {
  chdir(this->mount_point_.get_base_dir().c_str());
  this->cgroup_.clean();
  this->mount_point_.umount();
}

Sandbox::~Sandbox() noexcept {
  sem_close(this->sem_);
  sem_unlink(this->id_.c_str());
}

}  // namespace sandbox
}  // namespace libra
}  // namespace astraea
