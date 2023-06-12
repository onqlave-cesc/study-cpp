#pragma once

#include <keymanager/types/types.h>

#include <vector>

class PlainStreamProcessor {
public:
  virtual void WriteHeader(AlogorithmDeserialiser algo) = 0;
  virtual void WritePacket(std::vector<unsigned char> packet) = 0;
};

class plainStreamProcessor : public PlainStreamProcessor {
public:
  void WriteHeader(AlogorithmDeserialiser algo);
  void WritePacket(std::vector<unsigned char> packet);
};
