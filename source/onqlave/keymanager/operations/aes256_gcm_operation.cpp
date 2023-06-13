#include <keymanager/types/types.h>
#include <keymanager/operations/aes128_gcm_operation.h>
#include <keymanager/operations/aes256_gcm_operation.h>

aes256GCMKeyOperation::aes256GCMKeyOperation(KeyFactory *factory_) : factory(factory_) {
  AesGcmKeyFormat* format_ = new AesGcmKeyFormat(16);
  format = format_;
}

KeyFormat* aes256GCMKeyOperation::GetFormat() {
  return nullptr;
}

KeyFactory* aes256GCMKeyOperation::GetFactory() {
  return nullptr ;
}
