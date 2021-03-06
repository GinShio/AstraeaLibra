/**
 * Autogenerated by Thrift Compiler (0.14.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef problem_TYPES_H
#define problem_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>


namespace astraea { namespace thrift { namespace data {

class Problem;

typedef struct _Problem__isset {
  _Problem__isset() : label(true), rgb(true), category(true), tag(true), total(true), ac(true), testcase(true) {}
  bool label :1;
  bool rgb :1;
  bool category :1;
  bool tag :1;
  bool total :1;
  bool ac :1;
  bool testcase :1;
} _Problem__isset;

class Problem : public virtual ::apache::thrift::TBase {
 public:

  Problem(const Problem&);
  Problem& operator=(const Problem&);
  Problem() : id(), name(), ordinal(0), is_public(0), detail(), mime(), time(0), memory(0), label(""), rgb("#000000"), category(""), total(0), ac(0), testcase(0) {

  }

  virtual ~Problem() noexcept;
  std::string id;
  std::string name;
  int32_t ordinal;
  bool is_public;
  std::string detail;
  std::string mime;
  int32_t time;
  int32_t memory;
  std::string label;
  std::string rgb;
  std::string category;
  std::vector<std::string>  tag;
  int32_t total;
  int32_t ac;
  int32_t testcase;

  _Problem__isset __isset;

  void __set_id(const std::string& val);

  void __set_name(const std::string& val);

  void __set_ordinal(const int32_t val);

  void __set_is_public(const bool val);

  void __set_detail(const std::string& val);

  void __set_mime(const std::string& val);

  void __set_time(const int32_t val);

  void __set_memory(const int32_t val);

  void __set_label(const std::string& val);

  void __set_rgb(const std::string& val);

  void __set_category(const std::string& val);

  void __set_tag(const std::vector<std::string> & val);

  void __set_total(const int32_t val);

  void __set_ac(const int32_t val);

  void __set_testcase(const int32_t val);

  bool operator == (const Problem & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    if (!(name == rhs.name))
      return false;
    if (!(ordinal == rhs.ordinal))
      return false;
    if (!(is_public == rhs.is_public))
      return false;
    if (!(detail == rhs.detail))
      return false;
    if (!(mime == rhs.mime))
      return false;
    if (!(time == rhs.time))
      return false;
    if (!(memory == rhs.memory))
      return false;
    if (__isset.label != rhs.__isset.label)
      return false;
    else if (__isset.label && !(label == rhs.label))
      return false;
    if (__isset.rgb != rhs.__isset.rgb)
      return false;
    else if (__isset.rgb && !(rgb == rhs.rgb))
      return false;
    if (__isset.category != rhs.__isset.category)
      return false;
    else if (__isset.category && !(category == rhs.category))
      return false;
    if (__isset.tag != rhs.__isset.tag)
      return false;
    else if (__isset.tag && !(tag == rhs.tag))
      return false;
    if (__isset.total != rhs.__isset.total)
      return false;
    else if (__isset.total && !(total == rhs.total))
      return false;
    if (__isset.ac != rhs.__isset.ac)
      return false;
    else if (__isset.ac && !(ac == rhs.ac))
      return false;
    if (__isset.testcase != rhs.__isset.testcase)
      return false;
    else if (__isset.testcase && !(testcase == rhs.testcase))
      return false;
    return true;
  }
  bool operator != (const Problem &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Problem & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(Problem &a, Problem &b);

std::ostream& operator<<(std::ostream& out, const Problem& obj);

}}} // namespace

#endif
