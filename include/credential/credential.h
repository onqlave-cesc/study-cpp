#pragma once

#include <fmt/core.h>

namespace credNs {
  class Credential {
  public:
    std::string AccessKey;
    std::string SigningKey;
    std::string SecretKey;

    void Valid();
  };
}  // namespace credNs
