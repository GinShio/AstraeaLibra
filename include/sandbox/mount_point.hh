#pragma once
#ifndef ASTRAEA_LIBRA_INCLUDE_SANDBOX_MOUNT_POINT_HH_
#define ASTRAEA_LIBRA_INCLUDE_SANDBOX_MOUNT_POINT_HH_ 1

#include "message_queue/submission_types.h"

#include <filesystem>
#include <string>

namespace astraea {
namespace libra {
namespace sandbox {

class MountPoint {
  ////////// constructor //////////
 public:
  MountPoint() = delete;
  MountPoint(const std::string& id);
  MountPoint(const MountPoint&) = delete;
  MountPoint(MountPoint&&) noexcept = default;

  ////////// destructor //////////
 public:
  ~MountPoint() noexcept = default;

  ////////// assign //////////
 public:
  MountPoint& operator=(const MountPoint&) = delete;
  MountPoint& operator=(MountPoint&&) = delete;

  ////////// function member //////////
 public:
  const std::filesystem::path& get_base_dir() const { return this->base_path; }
  const std::filesystem::path& get_upper_dir() const { return this->upper; }
  const std::filesystem::path& get_merged_dir() const { return this->merged; }
  void mount(const astraea::thrift::mq::SubmissinoInfo & submit,
             const std::string& code_file);
  void umount() const;

  ////////// member variable //////////
 public:
  std::filesystem::path base_path;
  std::filesystem::path upper;
  std::filesystem::path merged;
};

}  // namespace sandbox
}  // namespace libra
}  // namespace astraea

#endif  // ASTRAEA_LIBRA_INCLUDE_SANDBOX_MOUNT_POINT_HH_
