#include <keymanager/types/types.h>
#include <keymanager/operations/aes128_gcm_operation.h>

AesGcmKeyFormat::AesGcmKeyFormat(unsigned int keySize) : KeySize(keySize) {}

unsigned int AesGcmKeyFormat::Size() {
    return 0;
}

aes128GCMKeyOperation::aes128GCMKeyOperation(KeyFactory* factory_): factory(factory_) {
  AesGcmKeyFormat* format_ = new AesGcmKeyFormat(16);
  format = format_;
}

KeyFormat* aes128GCMKeyOperation::GetFormat() {
  return nullptr;
}

KeyFactory* aes128GCMKeyOperation::GetFactory() {
  return nullptr ;
}
