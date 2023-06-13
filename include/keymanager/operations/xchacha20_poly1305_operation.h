#pragma once

#include <keymanager/types/types.h>

class XChaChaKeyFormat : public KeyFormat {
public:
  unsigned int KeySize;
  unsigned int Version;

  XChaChaKeyFormat(unsigned int keySize);

  unsigned int Size();
};

class xChaCha20Poly1305KeyOperation : public KeyOperation {
private:
  KeyFactory* factory;
  XChaChaKeyFormat* format;

public:
  xChaCha20Poly1305KeyOperation(KeyFactory* factory);

  KeyFormat* GetFormat();
  KeyFactory* GetFactory();
};
