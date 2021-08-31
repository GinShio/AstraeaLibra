/**
 * @file: include/utils/file.hh
 *
 * @author:  GinShio <iris@ginshio.org>
 *
 * @date:    2021-04-08 16:46:51
 *
 * @details:
 */

#pragma once
#ifndef ASTRAEA_LIBRA_INCLUDE_UTILS_FILE_HH_
#define ASTRAEA_LIBRA_INCLUDE_UTILS_FILE_HH_ 1

#include <filesystem>
#include <string>

#include <fcntl.h>

namespace astraea {
namespace libra {
namespace utils {

class File {
  ////////// constructor //////////
 public:
  File();
  File(const char* file, int flag = O_RDONLY);
  explicit File(const std::string& file, int flag = O_RDONLY);
  explicit File(const std::filesystem::path& file, int flag = O_RDONLY);
  File(const File&) = delete;
  File(File&&) noexcept = default;

  ////////// destructor //////////
 public:
  ~File() noexcept;

  ////////// assign //////////
 public:
  File& operator=(const File&) = delete;
  File& operator=(File&&) = delete;

  ////////// impl //////////
 public:
  void read(char* buffer, const std::size_t& len) const;
  void write(const std::string& context);
  void write(const char* context, const std::size_t& len);
  void reset(const char* file, int flag = O_RDONLY) const;
  void reset(const std::string& file, int flag = O_RDONLY) const;
  void reset(const std::filesystem::path& file, int flag = O_RDONLY) const;

 private:
  void __open(const char* file, const int& flag) const;
  void __close() const;
  void __write(const char* context, const std::size_t& size);

  ////////// member variable //////////
 private:
  mutable int fd;
};

}  // namespace utils
}  // namespace libra
}  // namespace astraea

#endif  // ASTRAEA_LIBRA_INCLUDE_UTILS_FILE_HH_
