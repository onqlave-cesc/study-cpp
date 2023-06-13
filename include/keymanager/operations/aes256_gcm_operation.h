#pragma once

#include <keymanager/types/types.h>

class aes256GCMKeyOperation : public KeyOperation {
private:
  KeyFactory* factory;
  AesGcmKeyFormat* format;

public:
  aes256GCMKeyOperation(KeyFactory* factory_);

  KeyFormat* GetFormat();
  KeyFactory* GetFactory();
};
