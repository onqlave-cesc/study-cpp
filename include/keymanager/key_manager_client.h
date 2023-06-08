#pragma once

#include <connection/connection.h>
#include <credential/credential.h>
#include <keymanager/types/types.h>

#include <map>
#include <string>
#include <tuple>
#include <vector>

const std::string ENCRYPT_RESOURCE_URL = "oe2/keymanager/encrypt";
const std::string DECRYPT_RESOURCE_URL = "oe2/keymanager/decrypt";

namespace keyNs {
  class Configuration {
  public:
    Credential *Cred;
    RetrySetting *Retry;
    std::string ArxURL;
    bool Debug;

    Configuration(Credential *Cred, RetrySetting *Retry, std::string ArxURL);
  };
}  // namespace keyManager

class KeyManager {
public:
  virtual std::tuple<std::vector<unsigned char>, std::vector<unsigned char>, std::string>
  FetchEncryptionKey() = 0;
  virtual std::tuple<std::vector<unsigned char>, std::string> FetchDecryptionKey(
      std::vector<unsigned char> edk)
      = 0;
};

class keyManager : public KeyManager {
private:
  Connection *conn;
  conNs::Configuration config;
  std::map<std::string, WrappingKeyOperation> operations;

  std::vector<unsigned char> unwrapKey(std::string wrappingAlgorithm, std::string operation,
                                       std::vector<unsigned char> wdk,
                                       std::vector<unsigned char> epk,
                                       std::vector<unsigned char> fp,
                                       std::vector<unsigned char> password);

public:
  std::tuple<std::vector<unsigned char>, std::vector<unsigned char>, std::string>
  FetchEncryptionKey();
  std::tuple<std::vector<unsigned char>, std::string> FetchDecryptionKey(
      std::vector<unsigned char> edk);
};
