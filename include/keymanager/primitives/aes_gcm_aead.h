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

  unsigned char* Encrypt(const unsigned char* plaintext, const unsigned char* associateData, unsigned char& ciphertext, unsigned long long& ciphertext_len) override;
  unsigned char* Decrypt(const unsigned char& ciphertext, const unsigned char* associateData) override;
};


