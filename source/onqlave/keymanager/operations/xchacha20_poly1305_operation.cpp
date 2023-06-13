#include <keymanager/operations/xchacha20_poly1305_operation.h>
#include <keymanager/types/types.h>

XChaChaKeyFormat::XChaChaKeyFormat(unsigned int keySize) : KeySize(keySize) {}

unsigned int XChaChaKeyFormat::Size() {
  return 0;
}

xChaCha20Poly1305KeyOperation::xChaCha20Poly1305KeyOperation(KeyFactory *factory_) : factory(factory_) {
  auto format_ = new XChaChaKeyFormat(16);
  format = format_;
}

KeyFormat* xChaCha20Poly1305KeyOperation::GetFormat() {
  return nullptr;
}

KeyFactory* xChaCha20Poly1305KeyOperation::GetFactory() {
  return nullptr ;
}
