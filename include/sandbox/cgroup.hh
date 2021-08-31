#pragma once
#ifndef ASTRAEA_LIBRA_INCLUDE_SANDBOX_CGROUP_HH_
#define ASTRAEA_LIBRA_INCLUDE_SANDBOX_CGROUP_HH_ 1

#include <filesystem>
#include <string>

namespace astraea {
namespace libra {
namespace sandbox {

//! sandbox cgroup setting
class CGroup {
  ////////// constructor //////////
 public:
  CGroup() = delete;
  CGroup(const std::string& id);
  CGroup(const CGroup&) = delete;
  CGroup(CGroup&&) noexcept = default;

  ////////// destructor //////////
 public:
  ~CGroup() noexcept;

  ////////// assign //////////
 public:
  CGroup& operator=(const CGroup&) = delete;
  CGroup& operator=(CGroup&&) = delete;

  ////////// subsystem //////////
 public:
  /**
   * @brief   set cgroup resources
   * @param   bytes: memory limit x Bytes
   * @return  void
   */
  void set_resources(const std::size_t& bytes);
  /**
   * @brief   set cgroup pid
   * @param   pid: limit pid
   * @return  void
   */
  void set_pid(const int& pid);
  void clean();

  ////////// member variable //////////
 private:
  std::filesystem::path mem_;
  std::filesystem::path cpu_;
  std::filesystem::path pid_;
};

}  // namespace sandbox
}  // namespace libra
}  // namespace astraea

#endif  // ASTRAEA_LIBRA_INCLUDE_SANDBOX_CGROUP_HH_
