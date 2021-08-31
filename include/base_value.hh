#pragma once
#ifndef ASTRAEA_LIBRA_INCLUDE_BASE_VALUE_HH_
#define ASTRAEA_LIBRA_INCLUDE_BASE_VALUE_HH_ 1

#include <filesystem>
#include <string_view>

namespace astraea {
namespace libra {
static constexpr std::string_view PROJECT_NAME = "libra";

/////////////// base directory name ///////////////
static constexpr std::string_view COMPILER_NAME = "compiler";
static constexpr std::string_view PROBLEM_NAME = "problem";
static constexpr std::string_view SANDBOX_NAME = "sandbox";
static constexpr std::string_view SECCOMP_NAME = "seccomp";

/////////////// filesystem path ///////////////
static const std::filesystem::path ROOT{"/"};
static const std::filesystem::path CGROUP_PATH{"/sys/fs/cgroup"};

/////////////// user / group id ///////////////
static const int UID_ROOT = 0;
static const int UID_NOBODY = 65534;
static const int GID_ROOT = 0;
static const int GID_NOBODY = 65534;

/////////////// Sandbox Type ///////////////
enum class SandboxType {
  COMPILE,
  RUN,
};

}  // namespace libra
}  // namespace astraea

#endif  // ASTRAEA_LIBRA_INCLUDE_BASE_VALUE_HH_
