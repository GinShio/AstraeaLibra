#include "utils/file.hh"

#include <climits>

#include <fcntl.h>
#include <unistd.h>

namespace astraea {
namespace libra {
namespace utils {

File::File() : fd(INT_MIN) {}

File::File(const char* file, int flag) {
  this->__open(file, flag);
}

File::File(const std::string& file, int flag) {
  this->__open(file.c_str(), flag);
}

File::File(const std::filesystem::path& file, int flag) {
  this->__open(file.c_str(), flag);
}

File::~File() {
  this->__close();
}

void File::read(char* buffer, const std::size_t& len) const {
  ::read(this->fd, buffer, len);
}

void File::write(const std::string& context) {
  this->__write(context.c_str(), context.size());
}

void File::write(const char* context, const std::size_t &len) {
  this->__write(context, len);
}

void File::reset(const char* file, int flag) const {
  this->__close();
  this->__open(file, flag);
}

void File::reset(const std::string& file, int flag) const {
  this->__close();
  this->__open(file.c_str(), flag);
}

void File::reset(const std::filesystem::path& file, int flag) const {
  this->__close();
  this->__open(file.c_str(), flag);
}

void File::__open(const char* file, const int& flag) const {
  this->fd = open(file, flag);
  if (this->fd == -1) {
    // TODO: throw file open error
  }
}

void File::__close() const {
  if (0 <= fd) {
    close(fd);
    fd = INT_MIN;
  }
}

void File::__write(const char* context, const std::size_t& size) {
  if (::write(this->fd, context, size) == -1) {
    // TODO: throw write error
  }
}

}  // namespace utils
}  // namespace libra
}  // namespace astraea
