#pragma once

#include <types/types.h>

#include <vector>

class PlainStreamProcessor {
public:
  virtual WriteHeader(AlogorithmDeserialiser algo) = 0;
  virtual WritePacket(std::vector<unsigned char> packet) = 0;
}

class plainStreamProcessor : public PlainStreamProcessor {
public:
  WriteHeader(AlogorithmDeserialiser algo);
  WritePacket(std::vector<unsigned char> packet);
}
