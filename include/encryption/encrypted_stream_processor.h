#pragma once

#include <types/types.h>

#include <vector>

class EncryptedStreamProcessor {
public:
  virtual AlogorithmDeserialiser ReadHeader() = 0;
  virtual std::vector<unsigned char> ReadPacket() = 0;
}

class encryptedStreamProcessor : public EncryptedStreamProcessor {
public:
  AlogorithmDeserialiser ReadHeader();
  std::vector<unsigned char> ReadPacket();
}
