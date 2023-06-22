#pragma once

#include <keymanager/types/types.h>
#include <string>
#include <map>

//std::map<int, std::string> algorithmTypeName = {
//    {0,"unknown_algorithm"},
//    {1,"aes-gcm-128"},
//    {2,"aes-gcm-256"},
//    {3,"xcha-cha-20-poly-1305"}
//};
//
//std::map<std::string, int> algorithmTypeValue = {
//    {"unknown_algorithm",0},
//    {"aes-gcm-128",1},
//    {"aes-gcm-256",2},
//    {"xcha-cha-20-poly-1305",3},
//};

class algorithm : public AlgorithmDeserialiser, public AlgorithmSerialiser {
private:
  unsigned int version;
  unsigned int algo;
  std::string key;

public:
  algorithm(unsigned int version_ = 0, unsigned int algo_ = 0, std::string key_ = "");

  std::string Serialise() override;
  int Deserialise(std::string buffer) override;
  std::string Key() override;
  int Version() override;
  std::string Algorithm() override;
};
