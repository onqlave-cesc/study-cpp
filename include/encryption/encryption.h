#pragma once

#include <encryption/options.h>
#include <keymanager/key_manager_client.h>
#include <keymanager/types/types.h>

#include <map>
#include <string>
#include <tuple>

class Encryption {
private:
  KeyManager *keyManager;
  std::map<std::string, KeyOperation *> operations;

  std::tuple<AlogorithmDeserialiser *, AEAD *> initEncryptOperation(std::string operation);
  AEAD *initDecryptOperation(std::string operation, AlogorithmDeserialiser *algo);

public:
  std::vector<unsigned char> Encrypt(std::vector<unsigned char> plainData, std::vector<unsigned char> associateData);

  std::vector<unsigned char> Decrypt(std::vector<unsigned char> cipherData, std::vector<unsigned char> associateData);
};
