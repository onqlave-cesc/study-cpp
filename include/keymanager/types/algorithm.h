#pragma once

#include <keymanager/types/types.h>
#include <string>

class algorithm : public AlgorithmDeserialiser, public AlgorithmSerialiser {
private:
  unsigned char version;
  unsigned char algo;
  std::string key;

public:
  std::string Serialise() override;
  int Deserialise(std::string buffer) override;
  std::string Key() override;
  std::string Version() override;
  std::string Algorithm() override;
};
