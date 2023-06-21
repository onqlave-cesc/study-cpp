#pragma once

#include <keymanager/types/types.h>
#include <string>

class AesGcmKeyData : public KeyData {
public:
  std::string typeUrl;
  std::string value;
  KeyMaterialType keyMaterialType;
  unsigned int version;

  AesGcmKeyData(std::string typeUrl_, std::string value_, KeyMaterialType type_, unsigned int version_);

  void FromValue(std::string data) override;
  std::string GetValue() override;
  std::string GetTypeURL() override;
  KeyMaterialType GetKeyMaterialType() override;
  unsigned int GetVersion() override;
};

class AesGcmKey : public Key {
private:
  KeyOperation* operation;
  AesGcmKeyData* data;
  KeyID* keyId;

public:
  AesGcmKey(KeyID* id_, KeyOperation* operation_, AesGcmKeyData* data_);

  KeyID * GetKeyID() override;
  KeyOperation * Operation() override;
  KeyData* Data() override;
};
