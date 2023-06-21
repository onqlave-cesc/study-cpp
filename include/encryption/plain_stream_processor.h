#pragma once

#include <keymanager/types/types.h>

#include <vector>

class PlainStreamProcessor {
public:
  virtual void WriteHeader(AlgorithmDeserialiser algo) = 0;
  virtual void WritePacket(std::vector<unsigned char> packet) = 0;
};

class plainStreamProcessor : public PlainStreamProcessor {
public:
  void WriteHeader(AlgorithmDeserialiser algo);
  void WritePacket(std::vector<unsigned char> packet);
};
