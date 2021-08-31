/**
 * Autogenerated by Thrift Compiler (0.14.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef submission_TYPES_H
#define submission_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>


namespace astraea { namespace thrift { namespace mq {

class ProblemLimit;

class SubmissinoInfo;

typedef struct _ProblemLimit__isset {
  _ProblemLimit__isset() : compilation_time(true), time_multiplier(true), compilation_memory(true), mem_multiplier(true), compilation_output(true), output(true) {}
  bool compilation_time :1;
  bool time_multiplier :1;
  bool compilation_memory :1;
  bool mem_multiplier :1;
  bool compilation_output :1;
  bool output :1;
} _ProblemLimit__isset;

class ProblemLimit : public virtual ::apache::thrift::TBase {
 public:

  ProblemLimit(const ProblemLimit&);
  ProblemLimit& operator=(const ProblemLimit&);
  ProblemLimit() : compilation_time(60000), time(0), time_multiplier(1.0000000000000000), compilation_memory(1048576), memory(0), mem_multiplier(1.0000000000000000), compilation_output(8192), output(256) {
  }

  virtual ~ProblemLimit() noexcept;
  int32_t compilation_time;
  int32_t time;
  double time_multiplier;
  int32_t compilation_memory;
  int32_t memory;
  double mem_multiplier;
  int32_t compilation_output;
  int32_t output;

  _ProblemLimit__isset __isset;

  void __set_compilation_time(const int32_t val);

  void __set_time(const int32_t val);

  void __set_time_multiplier(const double val);

  void __set_compilation_memory(const int32_t val);

  void __set_memory(const int32_t val);

  void __set_mem_multiplier(const double val);

  void __set_compilation_output(const int32_t val);

  void __set_output(const int32_t val);

  bool operator == (const ProblemLimit & rhs) const
  {
    if (!(compilation_time == rhs.compilation_time))
      return false;
    if (!(time == rhs.time))
      return false;
    if (!(time_multiplier == rhs.time_multiplier))
      return false;
    if (!(compilation_memory == rhs.compilation_memory))
      return false;
    if (!(memory == rhs.memory))
      return false;
    if (!(mem_multiplier == rhs.mem_multiplier))
      return false;
    if (!(compilation_output == rhs.compilation_output))
      return false;
    if (!(output == rhs.output))
      return false;
    return true;
  }
  bool operator != (const ProblemLimit &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ProblemLimit & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ProblemLimit &a, ProblemLimit &b);

std::ostream& operator<<(std::ostream& out, const ProblemLimit& obj);

typedef struct _SubmissinoInfo__isset {
  _SubmissinoInfo__isset() : problem_testcase_last_update(false), script_last_update(false) {}
  bool problem_testcase_last_update :1;
  bool script_last_update :1;
} _SubmissinoInfo__isset;

class SubmissinoInfo : public virtual ::apache::thrift::TBase {
 public:

  SubmissinoInfo(const SubmissinoInfo&);
  SubmissinoInfo& operator=(const SubmissinoInfo&);
  SubmissinoInfo() : id(), problem(), language(), code(), problem_testcase_last_update(), script_last_update() {
  }

  virtual ~SubmissinoInfo() noexcept;
  std::string id;
  std::string problem;
  std::string language;
  std::vector<std::string>  extensions;
  std::string code;
  ProblemLimit limits;
  std::string problem_testcase_last_update;
  std::string script_last_update;

  _SubmissinoInfo__isset __isset;

  void __set_id(const std::string& val);

  void __set_problem(const std::string& val);

  void __set_language(const std::string& val);

  void __set_extensions(const std::vector<std::string> & val);

  void __set_code(const std::string& val);

  void __set_limits(const ProblemLimit& val);

  void __set_problem_testcase_last_update(const std::string& val);

  void __set_script_last_update(const std::string& val);

  bool operator == (const SubmissinoInfo & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    if (!(problem == rhs.problem))
      return false;
    if (!(language == rhs.language))
      return false;
    if (!(extensions == rhs.extensions))
      return false;
    if (!(code == rhs.code))
      return false;
    if (!(limits == rhs.limits))
      return false;
    if (__isset.problem_testcase_last_update != rhs.__isset.problem_testcase_last_update)
      return false;
    else if (__isset.problem_testcase_last_update && !(problem_testcase_last_update == rhs.problem_testcase_last_update))
      return false;
    if (__isset.script_last_update != rhs.__isset.script_last_update)
      return false;
    else if (__isset.script_last_update && !(script_last_update == rhs.script_last_update))
      return false;
    return true;
  }
  bool operator != (const SubmissinoInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SubmissinoInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(SubmissinoInfo &a, SubmissinoInfo &b);

std::ostream& operator<<(std::ostream& out, const SubmissinoInfo& obj);

}}} // namespace

#endif