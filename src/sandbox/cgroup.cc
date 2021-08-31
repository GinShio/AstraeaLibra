#include "sandbox/cgroup.hh"

#include "base_value.hh"
#include "utils/file.hh"

#include <string_view>

#include <fcntl.h>
#include <unistd.h>

namespace astraea {
namespace libra {
namespace sandbox {

/////////////// namespace ///////////////
namespace fs = std::filesystem;
using namespace std::literals::string_literals;
using namespace std::literals::string_view_literals;

/////////////// cgroup private vaeiable ///////////////
namespace {
constexpr std::string_view SUBSYS_MEM = "memory"sv;
constexpr std::string_view SUBSYS_CPU = "cpu"sv;
constexpr std::string_view SUBSYS_PID = "pids"sv;
}

/////////////// cgroup private function ///////////////
namespace {
void __write(utils::File& f, const fs::path& file, const std::string& context) {
  static const int flag = O_WRONLY | O_TRUNC | O_CREAT;
  f.reset(file, flag);
  f.write(context);
}
}

/////////////// class cgroup implement ///////////////
CGroup::CGroup(const std::string& id) :
    mem_(astraea::libra::CGROUP_PATH / SUBSYS_MEM / id),
    cpu_(astraea::libra::CGROUP_PATH / SUBSYS_CPU / id),
    pid_(astraea::libra::CGROUP_PATH / SUBSYS_PID / id) {
  // create cgroup subsystem: memory, cpu, pids
  fs::create_directories(this->mem_);
  fs::create_directories(this->cpu_);
  fs::create_directories(this->pid_);
  // init cgroup
  utils::File f{};
  __write(f, this->cpu_ / "cpu.cfs_period_us"sv, "1000000"s);
  __write(f, this->cpu_ / "cpu.cfs_quota_us"sv, "900000"s);
  __write(f, this->pid_ / "pids.max"sv, "12"s);
  __write(f, this->mem_ / "memory.oom_control"sv, "0"s); // enable oom-kill
  __write(f, this->mem_ / "memory.swappiness"sv, "0"s); // disable swap
}

CGroup::~CGroup() {
  fs::remove_all(this->mem_);
  fs::remove_all(this->cpu_);
  fs::remove_all(this->pid_);
}

void CGroup::set_resources(const std::size_t& bytes) {
  utils::File f;
  std::string context;
  // set memory limit
  context = std::to_string(bytes);
  __write(f, this->mem_ / "memory.limit_in_bytes"sv, context);
  __write(f, this->mem_ / "memory.kmem.limit_in_bytes"sv, context);
}

void CGroup::set_pid(const int& pid) {
  utils::File f;
  std::string __str_pid = std::to_string(pid);
  __write(f, this->cpu_ / "tasks", __str_pid);
  __write(f, this->mem_ / "tasks", __str_pid);
  __write(f, this->pid_ / "tasks", __str_pid);
}

void CGroup::clean() {
  utils::File f;
  std::string __clean;
  __write(f, this->cpu_ / "tasks", __clean);
  __write(f, this->mem_ / "tasks", __clean);
  __write(f, this->pid_ / "tasks", __clean);
}

}  // namespace sandbox
}  // namespace libra
}  // namespace astraea
