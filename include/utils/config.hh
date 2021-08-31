#pragma once
#ifndef ASTRAEA_LIBRA_INCLUDE_UTILS_CONFIG_HH_
#define ASTRAEA_LIBRA_INCLUDE_UTILS_CONFIG_HH_ 1

#include <filesystem>
#include <string_view>
#include <vector>

namespace astraea {
namespace libra {
namespace utils {

void parse_config(std::string_view file);

class Config {
 public:
  static const std::filesystem::path& project_path();
  static const std::filesystem::path& compiler_script();
  static const std::filesystem::path& sandbox_worker();
  static const std::filesystem::path& problem_ans();
  static const std::vector<std::string>& languages();
  static const std::vector<int>& seccomp_blacklist();
  static const std::string& amqp_url();
  static const std::string& core_address();
};

}  // namespace utils
}  // namespace libra
}  // namespace astraea

#endif  // ASTRAEA_LIBRA_INCLUDE_UTILS_CONFIG_HH_
