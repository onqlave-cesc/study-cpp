#include <keymanager/operations/rsa_ssa_pkcs1_sha_operation.h>

rsaSSAPKCS1SHA2562048KeyOperation::rsaSSAPKCS1SHA2562048KeyOperation(WrappingKeyFactory* factory_)
    : factory(factory_) {}

KeyFormat* rsaSSAPKCS1SHA2562048KeyOperation::GetFormat() { return nullptr; }

WrappingKeyFactory* rsaSSAPKCS1SHA2562048KeyOperation::GetFactory() { return nullptr; }
