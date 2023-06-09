#pragma once

#include <string>
#include <vector>

enum HashType {
  HashTypeUNKNOWNHASH,
  HashTypeSHA1,
  HashTypeSHA384,
  HashTypeSHA256,
  HashTypeSHA512,
  HashTypeSHA224
};

enum KeyMaterialType {
  KeyMaterialUNKNOWNKEYMATERIAL,
  KeyMaterialSYMMETRIC,
  KeyMaterialASYMMETRICPRIVATE,
  KeyMaterialASYMMETRICPUBLIC,
  KeyMaterialREMOTE
};

constexpr const char Aesgcm128[] = "aes-gcm-128";
constexpr const char Aesgcm256[] = "aes-gcm-256";
constexpr const char XChacha20poly1305[] = "xcha-cha-20-poly-1305";
constexpr const char RsaSsapkcs12048sha256f4[] = "RSA_SSA_PKCS1_2048_SHA256_F4";

class Key;
class KeyID;
class KeyData;
class KeyOperation;
class WrappingKeyFactory;

class AEAD {
public:
  virtual std::vector<unsigned char> Encrypt(std::vector<unsigned char> plaintext,
                                             std::vector<unsigned char> associateData)
      = 0;
  virtual std::vector<unsigned char> Decrypt(std::vector<unsigned char> plaintext,
                                             std::vector<unsigned char> associateData)
      = 0;
};

class AlogorithmDeserialiser {
public:
  virtual int Deserialise(std::vector<unsigned char> buffer) = 0;
  virtual std::vector<unsigned char> Key() = 0;
  virtual std::vector<unsigned char> Version() = 0;
  virtual std::string Algorithm() = 0;
};

class KeyFormat {
public:
  virtual unsigned int Size() = 0;
};

class Unwrapping {
public:
  virtual std::vector<unsigned char> UnwrapKey(std::vector<unsigned char> wdk,
                                               std::vector<unsigned char> epk,
                                               std::vector<unsigned char> fp,
                                               std::vector<unsigned char> byte)
      = 0;
};

class KeyFactory {
public:
  virtual Key* NewKey(KeyOperation* operation) = 0;
  virtual Key* NewKeyFromData(KeyOperation* operation, std::vector<unsigned char> keyData) = 0;
  virtual AEAD* Primitive(Key* key) = 0;
};

class KeyOperation {
public:
  virtual KeyFormat* GetFormat() = 0;
  virtual KeyFactory* GetFactory() = 0;
};

class WrappingKeyOperation {
public:
  virtual KeyFormat* GetFormat() = 0;
  virtual WrappingKeyFactory* GetFactory() = 0;
};

class WrappingKeyFactory {
public:
  virtual Unwrapping* Primative(WrappingKeyOperation* operation) = 0;
};

class KeyData {
public:
  virtual std::vector<unsigned char> GetValue() = 0;
  virtual void FromValue(std::vector<unsigned char> data) = 0;
  virtual std::string GetTypeURL() = 0;
  virtual KeyMaterialType GetKeyMaterialType() = 0;
  virtual unsigned int GetVersion() = 0;
};

class Key {
public:
  virtual KeyID* GetKeyID() = 0;
  virtual KeyOperation* Operation() = 0;
  virtual KeyData Data() = 0;
};
