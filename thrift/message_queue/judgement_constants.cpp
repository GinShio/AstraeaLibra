/**
 * Autogenerated by Thrift Compiler (0.14.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "judgement_constants.h"

namespace astraea { namespace thrift { namespace mq {

const judgementConstants g_judgement_constants;

judgementConstants::judgementConstants() {
  JudgementName.insert(std::make_pair((JudgementType::type)1, "Accepted"));
  JudgementName.insert(std::make_pair((JudgementType::type)0, "Compile Error"));
  JudgementName.insert(std::make_pair((JudgementType::type)5, ""));
  JudgementName.insert(std::make_pair((JudgementType::type)3, "Run-Time Error"));
  JudgementName.insert(std::make_pair((JudgementType::type)2, "Time Limit Exceeded"));
  JudgementName.insert(std::make_pair((JudgementType::type)4, "Wrong Answer"));

}

}}} // namespace

