#pragma once

#include <keymanager/types/types.h>

#include <vector>

class EncryptedStreamProcessor {
public:
  virtual AlgorithmDeserialiser ReadHeader() = 0;
  virtual std::vector<unsigned char> ReadPacket() = 0;
};

class encryptedStreamProcessor : public EncryptedStreamProcessor {
public:
  AlgorithmDeserialiser ReadHeader();
  std::vector<unsigned char> ReadPacket();
};
