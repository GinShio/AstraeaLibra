#include "message_queue/judgement_constants.h"
#include "message_queue/judgement_types.h"
#include "message_queue/submission_types.h"
#include "sandbox/sandbox.hh"
#include "utils/base64.hh"
#include "utils/config.hh"

#include <memory>
#include <string>
#include <thread>

#include <amqpcpp.h>
#include <amqpcpp/libevent.h>
#include <event2/event.h>
#include <thrift/protocol/TCompactProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <uuid/uuid.h>

#include <iostream>

namespace astraea {
namespace libra {
namespace utils {

using namespace std::literals::chrono_literals;

namespace {
const std::string EXCHANGE_NAME{"astraea_submission_exchange"};

std::string get_queue_name(const std::string& tag) {
  return "astraea_submission_" + tag + "_queue";
}

void set_result(astraea::thrift::mq::JudgementInfo& judgement,
                const astraea::thrift::mq::SubmissinoInfo& submission) {
  judgement.id = std::move(submission.id);
  judgement.problem = std::move(submission.problem);
  judgement.language = std::move(submission.language);
  judgement.code = std::move(submission.code);
}

void reset_result(astraea::thrift::mq::JudgementInfo& judgement) {
  judgement.judgement_type = astraea::thrift::mq::JudgementType::NONE;
  judgement.message = "";
}

template <typename Val>
std::string __print_value(const Val& value) {
  std::stringstream ss;
  ss << value;
  return ss.str();
}
template <typename Key, typename Val>
std::string __print_value(const std::pair<Key, Val>& value) {
  std::stringstream ss;
  ss << "{" << value.first << "," << value.second << "}";
  return ss.str();
}

template <typename Container>
std::string __print_container(Container& c) {
  std::stringstream ss;
  ss << "[";
  for (const auto& value : c) {
    ss << __print_value(value);
    ss << ",";
  }
  ss << "]";
  return ss.str();
}

std::string __print_limit(const astraea::thrift::mq::ProblemLimit& limit) {
  std::stringstream ss;
  ss << "    compilation_time: " << limit.compilation_time << "ms" << std::endl
     << "    time: " << limit.time << "ms" << std::endl
     << "    time_multiplier: " << limit.time_multiplier << std::endl
     << "    compilation_memory: " << limit.compilation_memory << "kiB" << std::endl
     << "    memory: " << limit.memory << "kiB" << std::endl
     << "    compilation_output: " << limit.compilation_output << "kiB" << std::endl
     << "    output: " << limit.output << "kiB" << std::endl;
  return ss.str();
}

void print_submission(astraea::thrift::mq::SubmissinoInfo& submission) {
  std::stringstream ss;
  ss << "id: " << submission.id << std::endl
     << "problem: " << submission.problem << std::endl
     << "language: " << submission.language << std::endl
     << "language extensions: " << __print_container(submission.extensions) << std::endl
     << "code: " << astraea::libra::utils::base64::decode(submission.code) << std::endl
     << "limits: " << std::endl << __print_limit(submission.limits) << std::endl;
  std::cout << ss.str();
}

void print_result(astraea::thrift::mq::JudgementInfo& judgement) {
  std::stringstream ss;
  ss << "id: " << judgement.id << std::endl
     << "problem: " << judgement.problem << std::endl
     << "language: " << judgement.language << std::endl
     << "code: " << astraea::libra::utils::base64::decode(judgement.code) << std::endl
     << "judgement: " << astraea::thrift::mq::g_judgement_constants.JudgementName.find(judgement.judgement_type)->second << std::endl
     << "message: " << judgement.message << std::endl;
  std::cout << ss.str();
}

std::string get_uuid() {
  uuid_t uuid;
  std::string uuid_str(UUID_STR_LEN - 1, '\0');
  uuid_generate_time_safe(uuid);
  uuid_unparse(uuid, const_cast<char*>(uuid_str.c_str()));
  return uuid_str;
}

thread_local astraea::libra::sandbox::Sandbox sandbox{get_uuid()};
thread_local auto trans =
    std::make_shared<apache::thrift::transport::TMemoryBuffer>();
thread_local auto proto =
    std::make_shared<apache::thrift::protocol::TCompactProtocol>(trans);
}

void init() {
  // init amqp
  event_base* event{event_base_new()};
  AMQP::LibEventHandler handler{event};
  AMQP::TcpConnection conn{
    &handler,
    AMQP::Address{astraea::libra::utils::Config::amqp_url()},
  };
  AMQP::TcpChannel chan{&conn};
  // set channel
  chan.setQos(1);
  chan.onReady([&chan]() {
    AMQP::Table arguments;
    arguments
        .set("x-message-ttl", 900000)
        .set("x-max-length", 8192)
        .set("x-overflow", "reject-publish")
        .set("x-max-priority", 5);
    chan.declareExchange(EXCHANGE_NAME, AMQP::direct, AMQP::durable);
    // listen queue
    for (const auto& name : astraea::libra::utils::Config::languages()) {
      const auto queue = get_queue_name(name);
      chan.declareQueue(queue, AMQP::durable, arguments)
          .onError([](const char* message) {
            std::string msg = std::string("declareQueue\n") + message + "\n";
            std::cout << msg;
          });
      chan.bindQueue(EXCHANGE_NAME, queue, name);
      chan.consume(queue)
          .onReceived([&chan](
              const AMQP::Message& message, uint64_t delivery_tag, bool) {
            trans->resetBuffer(
                reinterpret_cast<uint8_t*>(
                    const_cast<char*>(message.body())),
                message.bodySize());
            sandbox.submit.read(proto.get());
            print_submission(sandbox.submit);
            reset_result(sandbox.result);
            sandbox.run();
            set_result(sandbox.result, sandbox.submit);
            // TODO: response result
            print_result(sandbox.result);
            chan.ack(delivery_tag);
          })
          .onError([](const char* message) {
            std::string msg = std::string("consume\n") + message + "\n";
            std::cout << msg;
          });
    }
  });
  // end
  event_base_dispatch(event);
  event_base_free(event);
}

}  // namespace utils
}  // namespace libra
}  // namespace astraea
