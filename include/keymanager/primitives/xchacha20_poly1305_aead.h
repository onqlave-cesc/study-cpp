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

  std::string Encrypt(std::string plaintext, std::string associateData) override;
  std::string Decrypt(std::string ciphertext, std::string associateData) override;
};
