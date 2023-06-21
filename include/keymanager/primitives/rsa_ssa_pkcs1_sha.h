#pragma once

#include <keymanager/types/types.h>
#include <keymanager/services/cprng_service.h>
#include <string>

class RSASSAPKCS1SHA : public Unwrapping {
private:
  CPRNGService* randomService;

public:
  RSASSAPKCS1SHA(CPRNGService* randomService_);

  std::string UnwrapKey(std::string wdk, std::string epk, std::string fp, std::string byte) override;
};
