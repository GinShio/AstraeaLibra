/**
 * Autogenerated by Thrift Compiler (0.14.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "judgement_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace astraea { namespace thrift { namespace mq {

int _kJudgementTypeValues[] = {
  JudgementType::CE,
  JudgementType::AC,
  JudgementType::TLE,
  JudgementType::RTE,
  JudgementType::WA,
  JudgementType::NONE
};
const char* _kJudgementTypeNames[] = {
  "CE",
  "AC",
  "TLE",
  "RTE",
  "WA",
  "NONE"
};
const std::map<int, const char*> _JudgementType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(6, _kJudgementTypeValues, _kJudgementTypeNames), ::apache::thrift::TEnumIterator(-1, nullptr, nullptr));

std::ostream& operator<<(std::ostream& out, const JudgementType::type& val) {
  std::map<int, const char*>::const_iterator it = _JudgementType_VALUES_TO_NAMES.find(val);
  if (it != _JudgementType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const JudgementType::type& val) {
  std::map<int, const char*>::const_iterator it = _JudgementType_VALUES_TO_NAMES.find(val);
  if (it != _JudgementType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}


JudgementInfo::~JudgementInfo() noexcept {
}


void JudgementInfo::__set_id(const std::string& val) {
  this->id = val;
}

void JudgementInfo::__set_problem(const std::string& val) {
  this->problem = val;
}

void JudgementInfo::__set_language(const std::string& val) {
  this->language = val;
}

void JudgementInfo::__set_code(const std::string& val) {
  this->code = val;
}

void JudgementInfo::__set_judgement_type(const JudgementType::type val) {
  this->judgement_type = val;
}

void JudgementInfo::__set_message(const std::string& val) {
  this->message = val;
__isset.message = true;
}

void JudgementInfo::__set_script_last_update(const std::string& val) {
  this->script_last_update = val;
__isset.script_last_update = true;
}
std::ostream& operator<<(std::ostream& out, const JudgementInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t JudgementInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_id = false;
  bool isset_problem = false;
  bool isset_language = false;
  bool isset_code = false;
  bool isset_judgement_type = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->id);
          isset_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->problem);
          isset_problem = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->language);
          isset_language = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->code);
          isset_code = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->judgement_type = (JudgementType::type)ecast0;
          isset_judgement_type = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->message);
          this->__isset.message = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->script_last_update);
          this->__isset.script_last_update = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_id)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_problem)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_language)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_code)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_judgement_type)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t JudgementInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("JudgementInfo");

  xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("problem", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->problem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("language", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->language);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("code", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->code);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("judgement_type", ::apache::thrift::protocol::T_I32, 9);
  xfer += oprot->writeI32((int32_t)this->judgement_type);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.message) {
    xfer += oprot->writeFieldBegin("message", ::apache::thrift::protocol::T_STRING, 10);
    xfer += oprot->writeString(this->message);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.script_last_update) {
    xfer += oprot->writeFieldBegin("script_last_update", ::apache::thrift::protocol::T_STRING, 12);
    xfer += oprot->writeString(this->script_last_update);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(JudgementInfo &a, JudgementInfo &b) {
  using ::std::swap;
  swap(a.id, b.id);
  swap(a.problem, b.problem);
  swap(a.language, b.language);
  swap(a.code, b.code);
  swap(a.judgement_type, b.judgement_type);
  swap(a.message, b.message);
  swap(a.script_last_update, b.script_last_update);
  swap(a.__isset, b.__isset);
}

JudgementInfo::JudgementInfo(const JudgementInfo& other1) {
  id = other1.id;
  problem = other1.problem;
  language = other1.language;
  code = other1.code;
  judgement_type = other1.judgement_type;
  message = other1.message;
  script_last_update = other1.script_last_update;
  __isset = other1.__isset;
}
JudgementInfo& JudgementInfo::operator=(const JudgementInfo& other2) {
  id = other2.id;
  problem = other2.problem;
  language = other2.language;
  code = other2.code;
  judgement_type = other2.judgement_type;
  message = other2.message;
  script_last_update = other2.script_last_update;
  __isset = other2.__isset;
  return *this;
}
void JudgementInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "JudgementInfo(";
  out << "id=" << to_string(id);
  out << ", " << "problem=" << to_string(problem);
  out << ", " << "language=" << to_string(language);
  out << ", " << "code=" << to_string(code);
  out << ", " << "judgement_type=" << to_string(judgement_type);
  out << ", " << "message="; (__isset.message ? (out << to_string(message)) : (out << "<null>"));
  out << ", " << "script_last_update="; (__isset.script_last_update ? (out << to_string(script_last_update)) : (out << "<null>"));
  out << ")";
}

}}} // namespace
