#include <keymanager/factories/rsa_ssa_pkcs1_sha_factory.h>

rsaSSAPKCS1SHAKeyFactory::rsaSSAPKCS1SHAKeyFactory(CPRNGService* randomService_)
    : randomService(randomService_) {}

Unwrapping* rsaSSAPKCS1SHAKeyFactory::Primative(WrappingKeyOperation* operation) { return nullptr; }
