#pragma once

#include <keymanager/types/types.h>

class AesGcmKeyFormat : public KeyFormat {
public:
  unsigned int KeySize;
  unsigned int Version;

  AesGcmKeyFormat(unsigned int keySize);

  unsigned int Size();
};

class aes128GCMKeyOperation : public KeyOperation {
private:
  KeyFactory* factory;
  AesGcmKeyFormat* format;

public:
  aes128GCMKeyOperation(KeyFactory* factory);

  KeyFormat* GetFormat();
  KeyFactory* GetFactory();
};
