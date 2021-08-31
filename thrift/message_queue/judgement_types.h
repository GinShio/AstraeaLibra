/**
 * Autogenerated by Thrift Compiler (0.14.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef judgement_TYPES_H
#define judgement_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>


namespace astraea { namespace thrift { namespace mq {

struct JudgementType {
  enum type {
    CE = 0,
    AC = 1,
    TLE = 2,
    RTE = 3,
    WA = 4,
    NONE = 5
  };
};

extern const std::map<int, const char*> _JudgementType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const JudgementType::type& val);

std::string to_string(const JudgementType::type& val);

class JudgementInfo;

typedef struct _JudgementInfo__isset {
  _JudgementInfo__isset() : message(false), script_last_update(false) {}
  bool message :1;
  bool script_last_update :1;
} _JudgementInfo__isset;

class JudgementInfo : public virtual ::apache::thrift::TBase {
 public:

  JudgementInfo(const JudgementInfo&);
  JudgementInfo& operator=(const JudgementInfo&);
  JudgementInfo() : id(), problem(), language(), code(), judgement_type((JudgementType::type)0), message(), script_last_update() {
  }

  virtual ~JudgementInfo() noexcept;
  std::string id;
  std::string problem;
  std::string language;
  std::string code;
  /**
   * 
   * @see JudgementType
   */
  JudgementType::type judgement_type;
  std::string message;
  std::string script_last_update;

  _JudgementInfo__isset __isset;

  void __set_id(const std::string& val);

  void __set_problem(const std::string& val);

  void __set_language(const std::string& val);

  void __set_code(const std::string& val);

  void __set_judgement_type(const JudgementType::type val);

  void __set_message(const std::string& val);

  void __set_script_last_update(const std::string& val);

  bool operator == (const JudgementInfo & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    if (!(problem == rhs.problem))
      return false;
    if (!(language == rhs.language))
      return false;
    if (!(code == rhs.code))
      return false;
    if (!(judgement_type == rhs.judgement_type))
      return false;
    if (__isset.message != rhs.__isset.message)
      return false;
    else if (__isset.message && !(message == rhs.message))
      return false;
    if (__isset.script_last_update != rhs.__isset.script_last_update)
      return false;
    else if (__isset.script_last_update && !(script_last_update == rhs.script_last_update))
      return false;
    return true;
  }
  bool operator != (const JudgementInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const JudgementInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(JudgementInfo &a, JudgementInfo &b);

std::ostream& operator<<(std::ostream& out, const JudgementInfo& obj);

}}} // namespace

#endif
