#pragma once

#include <keymanager/types/types.h>

class RsaSsaPkcs1KeyFormat : public KeyFormat {
public:
  unsigned int Version;
  HashType Hash;

  unsigned int Size();
};

class rsaSSAPKCS1SHA2562048KeyOperation : public WrappingKeyOperation {
public:
  WrappingKeyFactory *factory;
  RsaSsaPkcs1KeyFormat *format;

  rsaSSAPKCS1SHA2562048KeyOperation(WrappingKeyFactory *factory_);

  KeyFormat* GetFormat();
  WrappingKeyFactory* GetFactory();
};
