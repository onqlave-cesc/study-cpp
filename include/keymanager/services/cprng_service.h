#pragma once

#include <vector>
#include <string>

class CPRNGService {
public:
  virtual std::string GetRandomBytes(unsigned int n) = 0;
  virtual unsigned int GetRandomUint32() = 0;
};

class cprgnService : public CPRNGService {
public:
  std::string GetRandomBytes(unsigned int n);
  unsigned int GetRandomUint32();
};
