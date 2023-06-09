#include <connection/connection.h>
#include <fmt/core.h>
#include <keymanager/factories/rsa_ssa_pkcs1_sha_factory.h>
#include <keymanager/key_manager_client.h>
#include <keymanager/services/cprng_service.h>
#include <keymanager/types/types.h>
#include <utils/hasher.h>

#include <map>

keyManager::keyManager(keyNs::Configuration config_, CPRNGService* randomService) {
  hasher* h = new hasher();
  std::size_t index = config_.ArxURL.rfind("/");
  conNs::Credential cred{config_.Cred.AccessKey, config_.Cred.SigningKey};
  conNs::Configuration connConfig{cred, config_.Retry, config_.ArxURL.substr(0, index),
                                  config_.ArxURL.substr(index)};
  connection* httpClient = new connection(connConfig, h);

  rsaSSAPKCS1SHAKeyFactory* factory = new rsaSSAPKCS1SHAKeyFactory(randomService);
  std::map<std::string, WrappingKeyOperation*> operations_;
  operations_.insert(
      std::make_pair<RsaSsapkcs12048sha256f4, new rsaSSAPKCS1SHA2562048KeyOperation(factory)>);

  conn = httpClient;
  config = config_;
  operations = operations_;
}

std::tuple<std::vector<unsigned char>, std::vector<unsigned char>, std::string>
keyManager::FetchEncryptionKey() {
  fmt::print("keyManager::FetchEncryptionKey");

  std::vector<unsigned char> edk;
  std::vector<unsigned char> dk;
  std::string algorithm = "";

  return std::make_tuple<edk, dk, algorithm>;
}

std::vector<unsigned char> keyManager::FetchDecryptionKey(std::vector<unsigned char> edk) {
  fmt::print("keyManager::FetchDecryptionKey");
  std::vector<unsigned char> dk;

  return dk;
}
