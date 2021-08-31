#include "sandbox/namespaces.hh"

#include "base_value.hh"
#include "utils/file.hh"

#include <filesystem>
#include <string>

#include <fcntl.h>
#include <unistd.h>

namespace astraea {
namespace libra {
namespace sandbox {

namespace fs = std::filesystem;

void Namespaces::user(pid_t pid) {
  utils::File f;
  fs::path pid_path = astraea::libra::ROOT / "proc" / std::to_string(pid);
  std::string context = "0 0 1";
  // mapping user
  f.reset(pid_path / "uid_map", O_WRONLY | O_TRUNC | O_CREAT);
  f.write(context);
  // mapping group
  f.reset(pid_path / "gid_map", O_WRONLY | O_TRUNC | O_CREAT);
  f.write(context);
}

}  // namespace sandbox
}  // namespace libra
}  // namespace astraea
