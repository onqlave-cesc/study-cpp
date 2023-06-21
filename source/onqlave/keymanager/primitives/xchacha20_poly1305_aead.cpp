#include <keymanager/services/cprng_service.h>
#include <keymanager/types/types.h>
#include <keymanager/primitives/xchacha20_poly1305_aead.h>

#include <string>

XChaCha20Poly1305AEAD::XChaCha20Poly1305AEAD(Key *key_, CPRNGService* randomService_) : key(key_), randomService(randomService_) {}

std::string XChaCha20Poly1305AEAD::Encrypt(std::string plaintext, std::string associateData) {
  return "";
}

std::string XChaCha20Poly1305AEAD::Decrypt(std::string ciphertext, std::string associateData) {
  return "";
}
