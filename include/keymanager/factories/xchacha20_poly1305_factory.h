#include <keymanager/services/cprng_service.h>
#include <keymanager/services/id_service.h>
#include <keymanager/types/types.h>

class xChaCha20Poly1305KeyFactory : public KeyFactory {
private:
  IDService* idService;
  CPRNGService* randomService;

public:
  xChaCha20Poly1305KeyFactory(IDService* idService_, CPRNGService* randomService_);

  Key* NewKey(KeyOperation* operation);
  Key* NewKeyFromData(KeyOperation* operation, std::vector<unsigned char> keyData);
  AEAD* Primitive(Key* key);
};
