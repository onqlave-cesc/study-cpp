#include <keymanager/services/cprng_service.h>
#include <keymanager/types/types.h>
#include <keymanager/primitives/aes_gcm_aead.h>

#include <string>

AESGCMAEAD::AESGCMAEAD(Key *key_, CPRNGService* randomService_) : randomService(randomService_) {
  auto keyData = key_->Data();
  auto keyValue = keyData->GetValue();

  key = keyValue;
}

std::string AESGCMAEAD::Encrypt(std::string plaintext, std::string associateData) {
  return "";
}

std::string AESGCMAEAD::Decrypt(std::string ciphertext, std::string associateData) {
  return "";
}