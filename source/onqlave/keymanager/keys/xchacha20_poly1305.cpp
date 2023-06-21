#include <keymanager/types/types.h>
#include <keymanager/key/xchacha20_poly1305.h>

void XChaCha20Poly1305KeyData::FromValue(std::string data) {
  return;
}

std::string XChaCha20Poly1305KeyData::GetValue() {
  return value;
}

std::string XChaCha20Poly1305KeyData::GetTypeURL() {
  return typeUrl;
}

KeyMaterialType XChaCha20Poly1305KeyData::GetKeyMaterialType() {
  return keyMaterialType;
}

unsigned int XChaCha20Poly1305KeyData::GetVersion() {
  return version;
}

XChaCha20Poly1305Key::XChaCha20Poly1305Key(KeyID *id_, KeyOperation *operation_, XChaCha20Poly1305KeyData *data_) : keyId(id_), operation(operation_), data(data_) {}

KeyID* XChaCha20Poly1305Key::GetKeyID() {
  return keyId;
}

KeyOperation* XChaCha20Poly1305Key::Operation() {
  return operation;
}

KeyData* XChaCha20Poly1305Key::Data() {
  return data;
}
