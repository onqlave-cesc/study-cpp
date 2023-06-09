#pragma once

#include <vector>

class CPRNGService {
public:
  virtual std::vector<unsigned char> GetRandomBytes(unsigned int n) = 0;
  virtual unsigned int GetRandomUint32() = 0;
};

class cprgnService {
public:
  std::vector<unsigned char> GetRandomBytes(unsigned int n);
  unsigned int GetRandomUint32();
};
