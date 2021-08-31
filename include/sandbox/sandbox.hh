#pragma once
#ifndef ASTRAEA_LIBRA_INCLUDE_SANDBOX_SANDBOX_HH_
#define ASTRAEA_LIBRA_INCLUDE_SANDBOX_SANDBOX_HH_ 1

#include "base_value.hh"
#include "message_queue/judgement_types.h"
#include "message_queue/submission_types.h"
#include "sandbox/cgroup.hh"
#include "sandbox/mount_point.hh"
#include "sandbox/namespaces.hh"
#include "sandbox/seccomp.hh"

#include <chrono>
#include <string>
#include <string_view>

#include <semaphore.h>

namespace astraea {
namespace libra {
namespace sandbox {

struct SandboxApply;

//! judger sandbox
class Sandbox {
  friend struct SandboxApply;
  ////////// constructor //////////
 public:
  Sandbox() = delete;
  Sandbox(const std::string& id);
  Sandbox(const Sandbox&) = delete;
  Sandbox(Sandbox&&) noexcept = default;

  ////////// destructor //////////
 public:
  ~Sandbox() noexcept;

  ////////// assign //////////
 public:
  Sandbox& operator=(const Sandbox&) = delete;
  Sandbox& operator=(Sandbox&&) = delete;

  ////////// impl //////////
 public:
  const std::string& get_id() const { return this->id_; }
  void run();
 private:
  bool __compile(SandboxApply* sandbox, unsigned char* stack);
  void __run(SandboxApply* sandbox, unsigned char* stack);
  void __clean();

  ////////// member variable //////////
 protected:
  std::string id_;
  sem_t* sem_;
  CGroup cgroup_;
  Namespaces namespaces_;
  MountPoint mount_point_;
  Seccomp seccomp_;

  ////////// submission info ///////////////
 public:
  astraea::thrift::mq::SubmissinoInfo submit;
  astraea::thrift::mq::JudgementInfo result;
};

}  // namespace sandbox
}  // namespace libra
}  // namespace astraea

#endif  // ASTRAEA_LIBRA_INCLUDE_SANDBOX_SANDBOX_HH_
