#pragma once

#include <string>

class OnqlaveRequest {
  virtual int GetContent() = 0;
};

class EncryptionOpenRequest : public OnqlaveRequest {
public:
  int GetContent();
};

class DecryptionOpenRequest : public OnqlaveRequest {
public:
  std::string EDK;
  int GetContent();
};
