#include "sandbox/mount_point.hh"
#include "utils/base64.hh"
#include "utils/config.hh"
#include "utils/file.hh"

#include <sys/mount.h>
#include <unistd.h>

namespace astraea {
namespace libra {
namespace sandbox {

/////////////// namespace ///////////////
namespace fs = std::filesystem;

/////////////// class mount point implement ///////////////
MountPoint::MountPoint(const std::string& id) :
    base_path(astraea::libra::utils::Config::sandbox_worker() / id) {
  fs::create_directory(base_path);
}

void MountPoint::mount(
    const astraea::thrift::mq::SubmissinoInfo & submit,
    const std::string& code_file) {
  using config = astraea::libra::utils::Config;
  fs::path path = this->base_path / submit.id;
  this->merged = path / "merged";
  this->upper = path / "upper";
  fs::path worker = path / "worker";
  fs::create_directory(path);
  fs::create_directory(this->upper);
  fs::create_directory(worker);
  fs::create_directory(this->merged);
  {
    utils::File file(upper / code_file, O_WRONLY | O_TRUNC | O_CREAT);
    file.write(astraea::libra::utils::base64::decode(submit.code));
  }
  std::string lower_dir =
      (config::problem_ans() / submit.problem).string() +
      ":" +
      (config::compiler_script() / submit.language).string();
  std::string mount_data = "lowerdir=" + lower_dir +
      ",upperdir=" + upper.string() +
      ",workdir=" + worker.string();
  // mount and chroot
  if (::mount("overlay", this->merged.c_str(),
              "overlay", 0, mount_data.c_str()) == -1) {
    // TODO: throw LibraError mount error
  }
}

void MountPoint::umount() const {
  if (::umount2(this->merged.c_str(), MNT_FORCE) == -1) {
    // TODO: throw LibraError umount error
  }
}

}  // namespace sandbox
}  // namespace libra
}  // namespace astraea
