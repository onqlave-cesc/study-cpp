#include <keymanager/services/cprng_service.h>
#include <keymanager/types/types.h>
#include <keymanager/primitives/xchacha20_poly1305_aead.h>
#include <sodium.h>

#include <string>
#include <iostream>
#include <cstring>

#define MESSAGE (const unsigned char *) "test"
#define MESSAGE_LEN 4
#define ADDITIONAL_DATA (const unsigned char *) "123456"
#define ADDITIONAL_DATA_LEN 6

XChaCha20Poly1305AEAD::XChaCha20Poly1305AEAD(Key *key_, CPRNGService* randomService_) : key(key_), randomService(randomService_) {}

unsigned char* XChaCha20Poly1305AEAD::Encrypt(const unsigned char* plaintext, const unsigned char* associateData, unsigned char& ciphertext, unsigned long long& ciphertext_len) {
  unsigned char nonce[crypto_aead_xchacha20poly1305_ietf_NPUBBYTES];
  unsigned char key[crypto_aead_xchacha20poly1305_ietf_KEYBYTES];

  crypto_aead_xchacha20poly1305_ietf_keygen(key);
  randombytes_buf(nonce, sizeof nonce);

  unsigned char ct[MESSAGE_LEN+crypto_aead_xchacha20poly1305_ietf_ABYTES];
  unsigned long long ct_len;

  int result = crypto_aead_xchacha20poly1305_ietf_encrypt(ct, &ct_len,
                                             MESSAGE, MESSAGE_LEN,
                                             ADDITIONAL_DATA, ADDITIONAL_DATA_LEN,
                                             nullptr, nonce, key);
  if(result != 0) {
    std::cout << "ERROR: " << result << std::endl;
    return nullptr ;
  }

  ciphertext = *ct;
  ciphertext_len = ct_len;
  std::cout << "DONE: " << ciphertext_len << std::endl;
  return nullptr;
}

unsigned char* XChaCha20Poly1305AEAD::Decrypt(const unsigned char& ciphertext, const unsigned char* associateData) {
  size_t mlen = strlen(reinterpret_cast<const char*>(ciphertext));
  size_t adlen = strlen(reinterpret_cast<const char*>(associateData));
  unsigned char decrypted[MESSAGE_LEN];
  unsigned long long decrypted_len;

  unsigned char nonce[crypto_aead_xchacha20poly1305_ietf_NPUBBYTES];
  unsigned char key[crypto_aead_xchacha20poly1305_ietf_KEYBYTES];

  int result = crypto_aead_xchacha20poly1305_ietf_decrypt(decrypted, &decrypted_len,
                                             NULL,
                                             &ciphertext, mlen,
                                             associateData, adlen,
                                             nonce, key);

  if(result != 0) {
    std::cout << "ERROR: " << result << std::endl;
    return nullptr;
  }
  std::cout << "DONE: " << std::endl;

  std::string str = std::string(reinterpret_cast<const char*>(decrypted), MESSAGE_LEN);
  std::cout << "DECIPHERTEXT: " << str << std::endl;
  return nullptr;
}
