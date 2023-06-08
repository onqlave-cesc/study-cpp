#pragma once

#include <types/types.h>
#include <services/cprng_service.h>

class rsaSSAPKCS1SHAKeyFactory {
public:
  CPRNGService *randomService;

  rsaSSAPKCS1SHAKeyFactory(CPRNGService *randomService_);
}

