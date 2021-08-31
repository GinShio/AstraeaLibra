/**
 * @file: include/utils/base64.hh
 *
 * @author:  GinShio <iris@ginshio.org>
 *
 * @date:    2021-05-23 15:54:25
 *
 * @details:
 */

#pragma once
#ifndef ASTRAEA_LIBRA_INCLUDE_UTILS_BASE64_HH_
#define ASTRAEA_LIBRA_INCLUDE_UTILS_BASE64_HH_ 1

#include <string>

namespace astraea {
namespace libra {
namespace utils {
namespace base64 {

std::string encode(const std::string& data);
std::string decode(const std::string& data);

}  // namespace base64
}  // namespace utils
}  // namespace libra
}  // namespace astraea

#endif  // ASTRAEA_LIBRA_INCLUDE_UTILS_BASE64_HH_
