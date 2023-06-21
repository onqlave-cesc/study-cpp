#pragma once

#include <keymanager/services/cprng_service.h>
#include <keymanager/types/types.h>

#include <string>

// AESGCMIVSize is the acceptable IV size defined by RFC 5116.
const int AESGCMIVSize = 12;
// AESGCMTagSize is the acceptable tag size defined by RFC 5116.
const int AESGCMTagSize = 16;

class AESGCMAEAD : public AEAD {
private:
  CPRNGService* randomService;
  std::string key;
  bool prependIV;

public:
  AESGCMAEAD(Key* key_, CPRNGService* randomService_);

  std::string Encrypt(std::string plaintext, std::string associateData) override;
  std::string Decrypt(std::string ciphertext, std::string associateData) override;
};


