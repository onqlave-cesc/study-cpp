#include <keymanager/factories/aes_gcm_factory.h>
#include <keymanager/services/cprng_service.h>
#include <keymanager/services/id_service.h>
#include <keymanager/types/types.h>

#include <string>

aesGcmKeyFactory::aesGcmKeyFactory(IDService *idService_, CPRNGService *randomService_) : idService(idService_), randomService(randomService_) {}

Key* aesGcmKeyFactory::NewKey(KeyOperation *operation) {
  return nullptr;
}

Key* aesGcmKeyFactory::NewKeyFromData(KeyOperation *operation, std::vector<unsigned char> keyData) {
  return nullptr ;
}

AEAD* aesGcmKeyFactory::Primitive(Key *key) {
  return nullptr;
}
