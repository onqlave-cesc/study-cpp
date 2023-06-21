#pragma once

#include <keymanager/types/types.h>
#include <string>

class XChaCha20Poly1305KeyData: public KeyData {
public:
  std::string typeUrl;
  std::string value;
  KeyMaterialType keyMaterialType;
  unsigned int version;

  void FromValue(std::string data) override;
  std::string GetValue() override;
  std::string GetTypeURL() override;
  KeyMaterialType GetKeyMaterialType() override;
  unsigned int GetVersion() override;
};

class XChaCha20Poly1305Key: public Key {
private:
  KeyOperation* operation;
  XChaCha20Poly1305KeyData* data;
  KeyID* keyId;

public:
  XChaCha20Poly1305Key(KeyID* id, KeyOperation* operation, XChaCha20Poly1305KeyData* data);

  KeyID * GetKeyID() override;
  KeyOperation * Operation() override;
  KeyData* Data() override;
};
