#include <encryption/encryption.h>
#include <encryption/options.h>
#include <fmt/core.h>
#include <keymanager/key_manager_client.h>
#include <keymanager/services/cprng_service.h>
#include <keymanager/services/id_service.h>
#include <keymanager/factories/aes_gcm_factory.h>
#include <keymanager/factories/xchacha20_poly1305_factory.h>
#include <keymanager/operations/aes128_gcm_operation.h>
#include <keymanager/operations/aes256_gcm_operation.h>
#include <keymanager/operations/xchacha20_poly1305_operation.h>
#include <keymanager/types/algorithm.h>

#include <map>
#include <tuple>
#include <vector>
#include <iostream>

Encryption::Encryption(std::vector<Option*> opts) {
  keyNs::Configuration options{.Cred = {}, .Retry = {}, .ArxURL = INVALID_ARX};

  if (!opts.empty()) {
    for (auto&& o : opts) {
      o->apply(options);
    }
  }

  CPRNGService* randomService = new cprgnService();
  IDService* idS = new idService(randomService);
  KeyManager* keyMng = new class keyManager(options, randomService);
  KeyFactory* aeadGcmKeyFactory = new aesGcmKeyFactory(idS, randomService);
  KeyFactory* xchchaKeyFactory = new xChaCha20Poly1305KeyFactory(idS, randomService);

  std::map<std::string, KeyOperation*> ops;
  ops.insert({Aesgcm128, new aes128GCMKeyOperation(aeadGcmKeyFactory)});
  ops.insert({Aesgcm256, new aes256GCMKeyOperation(aeadGcmKeyFactory)});
  ops.insert({XChacha20poly1305, new xChaCha20Poly1305KeyOperation(xchchaKeyFactory)});

  keyManager = keyMng;
  operations = ops;
}

std::tuple<AlgorithmDeserialiser*, AEAD*> Encryption::initEncryptOperation(std::string operation) {
  fmt::print("Encryption::initEncryptOperation\n");
  auto encTup = keyManager->FetchEncryptionKey();
  std::string edk;
  std::string dk;
  std::string algoStr;
  std::tie(edk, dk, algoStr) = encTup;
  auto ops = operations[algoStr];
  auto factory = ops->GetFactory();
  auto key = factory->NewKeyFromData(ops, dk);
  auto primitive = factory->Primitive(key);
  algorithm algo = algorithm();

  return std::make_tuple(&algo, primitive);
}

AEAD* Encryption::initDecryptOperation(std::string operation, AlgorithmDeserialiser* algo) {
  fmt::print("Encryption::initDecryptOperation\n");

  AEAD* aead;
  return aead;
}

std::vector<unsigned char> Encryption::Encrypt(std::vector<unsigned char> plainData,
                                               std::vector<unsigned char> associateData) {
  auto initTup = Encryption::initEncryptOperation("Encrypt");
  fmt::print("Encryption::Encrypt\n");
  auto primitive = std::get<1>(initTup);
//  auto cipherData = primitive->Encrypt(reinterpret_cast<const unsigned char*>("plainData"), reinterpret_cast<const unsigned char*>("associatedata"));
//  auto cipherStr = std::string(reinterpret_cast<const char*>(cipherData));
//  std::cout << "=============CIPHER STRING: " << cipherStr << std::endl;
  std::vector<unsigned char> byte = {};
  return byte;
}

std::vector<unsigned char> Encryption::Decrypt(std::vector<unsigned char> cipherData,
                                               std::vector<unsigned char> associateData) {
  auto aead = Encryption::initDecryptOperation("Decrypt", nullptr);
  fmt::print("Encryption::Decrypt\n");
  std::vector<unsigned char> byte = {};
  keyManager->FetchDecryptionKey(byte);
  return byte;
}
