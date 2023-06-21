#pragma once

#include <contracts/requests/requests.h>

#include <map>
#include <string>

class Hasher {
  virtual std::string Digest(const OnqlaveRequest& body) = 0;
  virtual std::string Sign(std::map<std::string, std::string>) = 0;
};

class hasher : public Hasher {
public:
  std::string Digest(const OnqlaveRequest& body);
  std::string Sign(std::map<std::string, std::string>);
};
