#include <keymanager/services/cprng_service.h>
#include <keymanager/services/id_service.h>
#include <keymanager/types/types.h>

#include <string>

idService::idService(CPRNGService* randomService_) : randomService(randomService_) {}

std::string idService::NewStringID() { return ""; }

KeyID* idService::NewKeyID() { return nullptr; }
