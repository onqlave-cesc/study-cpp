#pragma once

#include <fmt/core.h>

class Credential {
public:
  std::string AccessKey;
  std::string SigningKey;
  std::string SecretKey;

  void Valid();
};

