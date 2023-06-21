#include <keymanager/types/types.h>
#include <keymanager/key/aes_gcm.h>

AesGcmKeyData::AesGcmKeyData(std::string typeUrl_, std::string value_, KeyMaterialType type_, unsigned int version_) :
 typeUrl(typeUrl_), value(value_), keyMaterialType(type_), version(version_) {}

void AesGcmKeyData::FromValue(std::string data) {
  return;
}

std::string AesGcmKeyData::GetValue() {
  return value;
}

std::string AesGcmKeyData::GetTypeURL() {
  return typeUrl;
}

KeyMaterialType AesGcmKeyData::GetKeyMaterialType() {
  return keyMaterialType;
}

unsigned int AesGcmKeyData::GetVersion() {
  return version;
}

AesGcmKey::AesGcmKey(KeyID* id_, KeyOperation* operation_, AesGcmKeyData* data_): keyId(id_), operation(operation_), data(data_) {}

KeyID* AesGcmKey::GetKeyID() {
  return keyId;
}

KeyOperation* AesGcmKey::Operation() {
  return operation;
}

KeyData* AesGcmKey::Data() {
  return data;
}
