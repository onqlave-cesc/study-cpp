#pragma once

#include <keymanager/services/cprng_service.h>
#include <keymanager/types/types.h>

class rsaSSAPKCS1SHAKeyFactory : public WrappingKeyFactory {
public:
  CPRNGService* randomService;

  rsaSSAPKCS1SHAKeyFactory(CPRNGService* randomService_);

  Unwrapping* Primative(WrappingKeyOperation* operation);
};
