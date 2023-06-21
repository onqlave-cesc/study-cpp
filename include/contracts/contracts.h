#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

struct EncryptionSecurityModel {
  std::string algorithm;
  std::string wrappingAlgorithm;
};

void to_json(json &j, const EncryptionSecurityModel &e) {
  j = {
      {"algo", e.algorithm},
      {"wrapping_algo", e.wrappingAlgorithm},
  };
}

void from_json(const json &j, EncryptionSecurityModel &e) {
  j.at("algo").get_to(e.algorithm);
  j.at("wrapping_algo").get_to(e.wrappingAlgorithm);
}

struct WrappingKey {
  std::string epk;
  std::string keyFingerprint;
};

void to_json(json &j, const WrappingKey &e) {
  j = {
      {"encrypted_private_key", e.epk},
      {"key_fingerprint", e.keyFingerprint},
  };
}

void from_json(const json &j, WrappingKey &e) {
  j.at("encrypted_private_key").get_to(e.epk);
  j.at("key_fingerprint").get_to(e.keyFingerprint);
}

struct DataEncryptionKey {
  std::string edk;
  std::string wdk;
};

void to_json(json &j, const DataEncryptionKey &e) {
  j = {
      {"encrypted_data_key", e.edk},
      {"wrapped_data_key", e.wdk},
  };
}

void from_json(const json &j, DataEncryptionKey &e) {
  j.at("encrypted_data_key").get_to(e.edk);
  j.at("wrapped_data_key").get_to(e.wdk);
}

struct DataDecryptionKey {
  std::string wdk;
};

void to_json(json &j, const DataDecryptionKey &e) {
  j = {
      {"wrapped_data_key", e.wdk},
  };
}

void from_json(const json &j, DataDecryptionKey &e) {
  j.at("wrapped_data_key").get_to(e.wdk);
}
