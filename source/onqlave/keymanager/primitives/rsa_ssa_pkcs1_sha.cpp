#include <keymanager/services/cprng_service.h>
#include <keymanager/primitives/rsa_ssa_pkcs1_sha.h>

#include <string>

RSASSAPKCS1SHA::RSASSAPKCS1SHA(CPRNGService *randomService_) : randomService(randomService_) {}

std::string RSASSAPKCS1SHA::UnwrapKey(std::string wdk, std::string epk, std::string fp, std::string byte) {
  return "";
}
