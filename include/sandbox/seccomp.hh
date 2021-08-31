/**
 * @file:    astraea/libra/include/sandbox/seccomp.hh
 *
 * @author:  GinShio <iris@ginshio.org>
 *
 * @date:    2021-03-05 20:01:11
 *
 * @details: seccomp-bpf setting for libra sandbox
 */

#pragma once
#ifndef ASTRAEA_LIBRA_INCLUDE_SANDBOX_SECCOMP_HH_
#define ASTRAEA_LIBRA_INCLUDE_SANDBOX_SECCOMP_HH_ 1

#include <vector>

namespace astraea {
namespace libra {
namespace sandbox {

class Seccomp {
  ////////// constructor //////////
 public:
  Seccomp();
  Seccomp(const Seccomp&) = delete;
  Seccomp(Seccomp&&) noexcept = default;

  ////////// destructor //////////
 public:
  ~Seccomp() noexcept = default;

  ////////// assign //////////
 public:
  Seccomp& operator=(const Seccomp&) = delete;
  Seccomp& operator=(Seccomp&&) = delete;

  ////////// member function //////////
 public:
  void apply() const;

  ////////// member variable //////////
 private:
  const std::vector<int>& blacklist_;
};

}  // namespace sandbox
}  // namespace libra
}  // namespace astraea

#endif  // ASTRAEA_LIBRA_INCLUDE_SANDBOX_SECCOMP_HH_
