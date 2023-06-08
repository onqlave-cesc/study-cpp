#include <encryption/encryption.h>
#include <encryption/options.h>
#include <fmt/core.h>
#include <keymanager/key_manager_client.h>

#include <memory>
#include <tuple>

std::tuple<AlogorithmDeserialiser*, AEAD*> Encryption::initEncryptOperation(std::string operation) {
  fmt::print("Encryption::initEncryptOperation\n");
  AlogorithmDeserialiser* algo;

  AEAD* aead;
  return std::make_tuple(algo, aead);
}

AEAD* Encryption::initDecryptOperation(std::string operation, AlogorithmDeserialiser* algo) {
  fmt::print("Encryption::initDecryptOperation\n");

  AEAD* aead;
  return aead;
}

std::vector<unsigned char> Encryption::Encrypt(std::vector<unsigned char> plainData,
                                               std::vector<unsigned char> associateData) {
  auto tup = Encryption::initEncryptOperation("Encrypt");
  fmt::print("Encryption::Encrypt\n");
  std::vector<unsigned char> byte = {};
  return byte;
}

std::vector<unsigned char> Encryption::Decrypt(std::vector<unsigned char> cipherData,
                                               std::vector<unsigned char> associateData) {
  auto aead = Encryption::initDecryptOperation("Decrypt", nullptr);
  fmt::print("Encryption::Decrypt\n");
  std::vector<unsigned char> byte = {};
  return byte;
}
