#include "sandbox/sandbox.hh"
#include "utils/config.hh"
#include "utils/mq.hh"

#include <filesystem>
#include <thread>

namespace fs = std::filesystem;

static const std::size_t thread_num_max =
    2 < std::thread::hardware_concurrency() ?
    (std::thread::hardware_concurrency() - 2) : 1;

inline void __one() { astraea::libra::utils::init(); }

void __all() {
  for (auto i = thread_num_max - 1; i > 0; --i) {
    std::thread t{astraea::libra::utils::init};
    t.detach();
  }
  __one();
}

int main(int argc, char* argv[]) {
  astraea::libra::utils::parse_config(argc < 2 ? "./config.toml" : argv[1]);
  fs::create_directories(astraea::libra::utils::Config::compiler_script());
  fs::create_directories(astraea::libra::utils::Config::problem_ans());
  fs::create_directories(astraea::libra::utils::Config::sandbox_worker());
  fs::permissions(astraea::libra::utils::Config::project_path(),
                  fs::perms::owner_all);
  thread_num_max > 1 ? __all() : __one();
}
