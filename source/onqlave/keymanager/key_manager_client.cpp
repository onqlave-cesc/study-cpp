#include <connection/connection.h>
#include <fmt/core.h>
#include <keymanager/factories/rsa_ssa_pkcs1_sha_factory.h>
#include <keymanager/key_manager_client.h>
#include <keymanager/operations/rsa_ssa_pkcs1_sha_operation.h>
#include <keymanager/services/cprng_service.h>
#include <keymanager/types/types.h>
#include <utils/hasher.h>

#include <map>
#include <tuple>

keyManager::keyManager(keyNs::Configuration config_, CPRNGService* randomService) {
  hasher* h = new hasher();
  std::size_t index = config_.ArxURL.rfind('/');
  conNs::Credential cred{config_.Cred.AccessKey, config_.Cred.SigningKey};
  conNs::Configuration connConfig{cred, config_.Retry, config_.ArxURL.substr(0, index),
                                  config_.ArxURL.substr(index)};
  connection* httpClient = new connection(connConfig, h);

  rsaSSAPKCS1SHAKeyFactory* factory = new rsaSSAPKCS1SHAKeyFactory(randomService);
  std::map<std::string, WrappingKeyOperation*> operations_;
  rsaSSAPKCS1SHA2562048KeyOperation* keyOp = new rsaSSAPKCS1SHA2562048KeyOperation(factory);
  operations_.insert({RsaSsapkcs12048sha256f4, keyOp});

  conn = httpClient;
  config = config_;
  operations = operations_;
}

std::tuple<std::vector<unsigned char>, std::vector<unsigned char>, std::string>
keyManager::FetchEncryptionKey() {
  fmt::print("keyManager::FetchEncryptionKey\n");

  std::vector<unsigned char> edk;
  std::vector<unsigned char> dk;
  std::string algorithm = "";

  OnqlaveRequest* body = new EncryptionOpenRequest();
  conn->Post(ENCRYPT_RESOURCE_URL, body);

  return std::make_tuple(edk, dk, algorithm);
}

std::vector<unsigned char> keyManager::FetchDecryptionKey(std::vector<unsigned char> edk) {
  fmt::print("keyManager::FetchDecryptionKey\n");
  std::vector<unsigned char> dk;
  return dk;
}
