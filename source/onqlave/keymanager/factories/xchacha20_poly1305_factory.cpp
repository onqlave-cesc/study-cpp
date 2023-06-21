#include <keymanager/factories/xchacha20_poly1305_factory.h>
#include <keymanager/services/cprng_service.h>
#include <keymanager/services/id_service.h>
#include <keymanager/types/types.h>

xChaCha20Poly1305KeyFactory::xChaCha20Poly1305KeyFactory(IDService *idService_, CPRNGService *randomService_): idService(idService_), randomService(randomService_) {}

Key* xChaCha20Poly1305KeyFactory::NewKey(KeyOperation *operation) {
  return nullptr ;
}

Key* xChaCha20Poly1305KeyFactory::NewKeyFromData(KeyOperation *operation, std::string keyData) {
  return nullptr ;
}

AEAD* xChaCha20Poly1305KeyFactory::Primitive(Key *key) {
  return nullptr;
}
