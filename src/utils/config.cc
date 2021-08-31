#include "utils/config.hh"

#include "base_value.hh"

#include <fstream>
#include <string>

#include <libseccomp/seccomp.h>
#include <toml++/toml.h>


#include <iostream>

namespace astraea {
namespace libra {
namespace utils {

using namespace std::literals::string_literals;
using namespace std::literals::string_view_literals;

namespace {
std::filesystem::path project_path;
std::filesystem::path compiler_script;
std::filesystem::path sandbox_worker;
std::filesystem::path problem_ans;
std::vector<std::string> languages;
std::vector<int> blacklist;
std::string amqp;
std::string core;

void parse_directories(const toml::table& list) {
  auto base = list.get_as<toml::string>("project_path"sv);
  project_path = base->value_or("/astraea"sv);
  compiler_script = project_path / astraea::libra::COMPILER_NAME;
  sandbox_worker = project_path / astraea::libra::SANDBOX_NAME;
  problem_ans = project_path / astraea::libra::PROBLEM_NAME;
}
void parse_languages(const toml::table& list) {
  auto support_languages = list.get_as<toml::array>("languages"sv);
  languages.reserve(support_languages->size());
  for (auto& elm : *support_languages) {
    languages.emplace_back(elm.value<std::string>().value());
  }
}
const std::string amqp_username() { return "guest"; }
template <typename TomlNode> const std::string amqp_username(TomlNode* node) {
  return node == nullptr ? amqp_username() : node->get();
}
const std::string amqp_password() { return "guest"; }
template <typename TomlNode> const std::string amqp_password(TomlNode* node) {
  return node == nullptr ? amqp_password() : node->get();
}
const std::string amqp_host() { return "localhost"; }
template <typename TomlNode> const std::string amqp_host(TomlNode* node) {
  return node == nullptr ? amqp_host() : node->get();
}
const std::string amqp_port() { return "5672"; }
template <typename TomlNode> std::string amqp_port(TomlNode* node) {
  return node == nullptr ? amqp_port() : std::to_string(node->get());
}
void parse_amqp(const toml::table& list) {
  std::string username, password, host, port;
  auto table = list.get_as<toml::table>("amqp"sv);
  if (table == nullptr) {
    username = amqp_username();
    password = amqp_password();
    host = amqp_host();
    port = amqp_port();
  } else {
    username = amqp_username(table->get_as<std::string>("username"));
    password = amqp_password(table->get_as<std::string>("password"));
    host = amqp_host(table->get_as<std::string>("host"));
    port = amqp_port(table->get_as<std::int64_t>("port"));
  }
  amqp = "amqp://" + username + ":" + password + "@" + host + ":" + port;
}
const std::string core_host() { return "localhost"; }
template <typename TomlNode> const std::string core_host(TomlNode* node) {
  return node == nullptr ? core_host() : node->get();
}
const std::string core_port() { return "5452"; }
template <typename TomlNode> std::string core_port(TomlNode* node) {
  return node == nullptr ? core_port() : std::to_string(node->get());
}
void parse_core(const toml::table& list) {
  std::string host, port;
  auto core_table = list.get_as<toml::table>("core"sv);
  if (core_table == nullptr) {
    host = core_host();
    port = core_port();
  } else {
    host = core_host(core_table->get_as<std::string>("host"));
    port = core_host(core_table->get_as<std::string>("port"));
  }
  core = host + ":" + port;
}
void parse_seccomp(const toml::table& list) {
  auto arr = list.get_as<toml::array>("blacklist"sv);
  blacklist.reserve(arr->size());
  for (auto&& elm : *arr) {
    int syscall_id =
        seccomp_syscall_resolve_name(elm.value<std::string>()->c_str());
    if (syscall_id != __NR_SCMP_ERROR) {
      blacklist.emplace_back(syscall_id);
    }
  }
}
}

void parse_config(std::string_view file) {
  auto list = toml::parse_file(file);
  parse_directories(list);
  parse_languages(list);
  parse_amqp(list);
  parse_core(list);
  parse_seccomp(list);
}

const std::filesystem::path& Config::project_path() {
  return astraea::libra::utils::project_path;
}
const std::filesystem::path& Config::compiler_script() {
  return astraea::libra::utils::compiler_script;
}
const std::filesystem::path& Config::sandbox_worker() {
  return astraea::libra::utils::sandbox_worker;
}
const std::filesystem::path& Config::problem_ans() {
  return astraea::libra::utils::problem_ans;
}
const std::vector<std::string>& Config::languages() { return utils::languages; }
const std::vector<int>& Config::seccomp_blacklist() { return blacklist; }
const std::string& Config::amqp_url() { return amqp; }
const std::string& Config::core_address() { return core; }

}  // namespace utils
}  // namespace libra
}  // namespace astraea
