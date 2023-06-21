#pragma once

#include <connection/connection.h>
#include <credential/credential.h>
#include <keymanager/services/cprng_service.h>
#include <keymanager/types/types.h>

#include <map>
#include <string>
#include <tuple>
#include <vector>

const std::string ENCRYPT_RESOURCE_URL = "oe2/keymanager/encrypt";
const std::string DECRYPT_RESOURCE_URL = "oe2/keymanager/decrypt";

namespace keyNs {
  struct Configuration {
    credNs::Credential Cred;
    RetrySetting Retry;
    std::string ArxURL;
    bool Debug;
  };
}  // namespace keyNs

class KeyManager {
public:
  virtual std::tuple<std::string, std::string, std::string> FetchEncryptionKey() = 0;
  virtual std::vector<unsigned char> FetchDecryptionKey(std::vector<unsigned char> edk) = 0;
};

class keyManager : public KeyManager {
private:
  Connection *conn;
  keyNs::Configuration config;
  std::map<std::string, WrappingKeyOperation *> operations;

  std::string unwrapKey(std::string wrappingAlgorithm,
                                                std::string operation,
                                                std::string wdk,
                                                std::string epk,
                                                std::string fp,
                                                std::string password);

public:
  keyManager(keyNs::Configuration config, CPRNGService *randomService);

  std::tuple<std::string, std::string, std::string> FetchEncryptionKey();

  std::vector<unsigned char> FetchDecryptionKey(std::vector<unsigned char> edk);
};
