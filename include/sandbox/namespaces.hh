#pragma once
#ifndef ASTRAEA_LIBRA_INCLUDE_SANDBOX_NAMESPACES_HH_
#define ASTRAEA_LIBRA_INCLUDE_SANDBOX_NAMESPACES_HH_ 1

#include <sys/types.h>

namespace astraea {
namespace libra {
namespace sandbox {

class Namespaces {
  ////////// constructor //////////
 public:
  Namespaces() = default;
  Namespaces(const Namespaces&) = delete;
  Namespaces(Namespaces&&) noexcept = default;

  ////////// destructor //////////
 public:
  ~Namespaces() noexcept = default;

  ////////// assign //////////
 public:
  Namespaces& operator=(const Namespaces&) = delete;
  Namespaces& operator=(Namespaces&&) = delete;

  ////////// namespaces //////////
 public:
  void user(pid_t pid);
};

}  // namespace sandbox
}  // namespace libra
}  // namespace astraea

#endif  // ASTRAEA_LIBRA_INCLUDE_SANDBOX_NAMESPACES_HH_
