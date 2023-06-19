#pragma once

#include <contracts/contracts.h>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

struct Error {
  std::string status;
  std::string message;
  std::string correlationID;
  std::string details;
  int code;
};

void to_json(json &j, const Error &e) {
  j = {
      {"status", e.status},
      {"message", e.message},
      {"correlation_id", e.correlationID},
      {"code", e.code}
  };
}

void from_json(const json &j, Error &e) {
  j.at("status").get_to(e.status);
  j.at("message").get_to(e.message);
  j.at("correlation_id").get_to(e.correlationID);
  j.at("code").get_to(e.code);
}

struct DecryptionOpenResponse {
  Error baseError;
  WrappingKey wk;
  EncryptionSecurityModel securityModel;
  DataDecryptionKey dk;
};

void to_json(json &j, const DecryptionOpenResponse &e) {
  j = {
      {"error", e.baseError},
      {"wrapping_key", e.wk},
      {"security_model", e.securityModel},
      {"data_key", e.dk}
  };
}

void from_json(const json &j, DecryptionOpenResponse &e) {
  j.at("error").get_to(e.baseError);
  j.at("wrapping_key").get_to(e.wk);
  j.at("security_model").get_to(e.securityModel);
  j.at("data_key").get_to(e.dk);
}

struct EncryptionOpenResponse {
  Error baseError;
  WrappingKey wk;
  EncryptionSecurityModel securityModel;
  DataEncryptionKey dk;
  unsigned int maxUses;
};

void to_json(json &j, const EncryptionOpenResponse &e) {
  j = {
      {"error", e.baseError},
      {"wrapping_key", e.wk},
      {"security_model", e.securityModel},
      {"data_key", e.dk},
      {"max_uses", e.maxUses}
  };
}

void from_json(const json &j, EncryptionOpenResponse &e) {
  j.at("error").get_to(e.baseError);
  j.at("wrapping_key").get_to(e.wk);
  j.at("security_model").get_to(e.securityModel);
  j.at("data_key").get_to(e.dk);
  j.at("max_uses").get_to(e.maxUses);
}
