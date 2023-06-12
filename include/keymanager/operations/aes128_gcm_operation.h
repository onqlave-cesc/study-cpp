#pragma once

#include <keymanager/types/types.h>

class AesGcmKeyFormat : public KeyFormat {
public:
  unsigned int KeySize;
  unsigned int Version

  unsigned int Size();
};
