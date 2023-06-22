#include <keymanager/services/cprng_service.h>
#include <keymanager/types/types.h>
#include <keymanager/primitives/aes_gcm_aead.h>

#include <string>

AESGCMAEAD::AESGCMAEAD(Key *key_, CPRNGService* randomService_) : randomService(randomService_) {
  auto keyData = key_->Data();
  auto keyValue = keyData->GetValue();

  key = keyValue;
}

unsigned char* AESGCMAEAD::Encrypt(const unsigned char* plaintext, const unsigned char* associateData, unsigned char& ciphertext, unsigned long long& ciphertext_len) {
  return nullptr;
}

unsigned char* AESGCMAEAD::Decrypt(const unsigned char& ciphertext, const unsigned char* associateData) {
  return nullptr;
}