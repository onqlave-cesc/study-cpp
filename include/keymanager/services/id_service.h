#pragma once

#include <keymanager/services/cprng_service.h>
#include <keymanager/types/types.h>

#include <string>

class IDService {
public:
  virtual std::string NewStringID() = 0;
  virtual KeyID* NewKeyID() = 0;
};

class idService : public IDService {
private:
  CPRNGService* randomService;

public:
  idService(CPRNGService* randomService_);

  std::string NewStringID() override;
  KeyID* NewKeyID() override;
};
