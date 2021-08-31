/**
 * Autogenerated by Thrift Compiler (0.14.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef error_TYPES_H
#define error_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>


namespace astraea { namespace thrift {

struct ErrorType {
  enum type {
    DATABASE = 0,
    CONNECTION = 1
  };
};

extern const std::map<int, const char*> _ErrorType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const ErrorType::type& val);

std::string to_string(const ErrorType::type& val);

class Error;


class Error : public ::apache::thrift::TException {
 public:

  Error(const Error&);
  Error& operator=(const Error&);
  Error() : code((ErrorType::type)0), message() {
  }

  virtual ~Error() noexcept;
  /**
   * 
   * @see ErrorType
   */
  ErrorType::type code;
  std::string message;

  void __set_code(const ErrorType::type val);

  void __set_message(const std::string& val);

  bool operator == (const Error & rhs) const
  {
    if (!(code == rhs.code))
      return false;
    if (!(message == rhs.message))
      return false;
    return true;
  }
  bool operator != (const Error &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Error & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
  mutable std::string thriftTExceptionMessageHolder_;
  const char* what() const noexcept;
};

void swap(Error &a, Error &b);

std::ostream& operator<<(std::ostream& out, const Error& obj);

}} // namespace

#endif
