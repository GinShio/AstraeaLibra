#include "sandbox/seccomp.hh"

#include "base_value.hh"
#include "utils/config.hh"

#include <filesystem>
#include <fstream>

#include <linux/sched.h>
#include <libseccomp/seccomp.h>

namespace astraea {
namespace libra {
namespace sandbox {

namespace fs = std::filesystem;


/////////////// seccomp private variable ///////////////
namespace {
constexpr unsigned long MASKED =
    CLONE_NEWNS | CLONE_NEWCGROUP | CLONE_NEWUTS |
    CLONE_NEWIPC | CLONE_NEWUSER | CLONE_NEWPID | CLONE_NEWNET;
}

/////////////// seccomp implement ///////////////
Seccomp::Seccomp() :
    blacklist_(astraea::libra::utils::Config::seccomp_blacklist()) {}

void Seccomp::apply() const {
  scmp_filter_ctx ctx = seccomp_init(SCMP_ACT_ALLOW);
  seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(clone), 1,
                   SCMP_A0(scmp_compare::SCMP_CMP_MASKED_EQ, MASKED, 0));
  for (const int& x : this->blacklist_) {
    seccomp_rule_add(ctx, SCMP_ACT_ERRNO(EPERM), x, 0);
  }
  seccomp_load(ctx);
  seccomp_release(ctx);
}

}  // namespace sandbox
}  // namespace libra
}  // namespace astraea
