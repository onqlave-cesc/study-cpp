#pragma once

#include <keymanager/services/cprng_service.h>
#include <keymanager/types/types.h>

#include <string>

const int poly1305TagSize = 16;

class XChaCha20Poly1305AEAD : public AEAD {
private:
  CPRNGService* randomService;
  Key* key;

public:
  XChaCha20Poly1305AEAD(Key* key_, CPRNGService* randomService_);

  unsigned char* Encrypt(const unsigned char* plaintext, const unsigned char* associateData, unsigned char& ciphertext, unsigned long long& ciphertext_len) override;
  unsigned char* Decrypt(const unsigned char& ciphertext, const unsigned char* associateData) override;
};
