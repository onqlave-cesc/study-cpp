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

const std::string Aesgcm128 = "aes-gcm-128";
const std::string Aesgcm256 = "aes-gcm-256";
const std::string XChacha20poly1305 = "xcha-cha-20-poly-1305";
const std::string RsaSsapkcs12048sha256f4 = "RSA_SSA_PKCS1_2048_SHA256_F4";

typedef int KeyID;

class Key;
class KeyData;
class KeyOperation;
class WrappingKeyFactory;

class AEAD {
public:
  virtual unsigned char* Encrypt(const unsigned char* plaintext, const unsigned char* associateData, unsigned char& ciphertext, unsigned long long& ciphertext_len) = 0;
  virtual unsigned char* Decrypt(const unsigned char&  ciphertext, const unsigned char*  associateData) = 0;
};

class AlgorithmSerialiser {
public:
  virtual std::string Serialise() = 0;
};

class AlgorithmDeserialiser {
public:
  virtual int Deserialise(std::string buffer) = 0;
  virtual std::string Key() = 0;
  virtual int Version() = 0;
  virtual std::string Algorithm() = 0;
};

class KeyFormat {
public:
  virtual unsigned int Size() = 0;
};

class Unwrapping {
public:
  virtual std::string UnwrapKey(std::string wdk,
                                std::string epk,
                                std::string fp,
                                std::string byte) = 0;
};

class KeyFactory {
public:
  virtual Key* NewKey(KeyOperation* operation) = 0;
  virtual Key* NewKeyFromData(KeyOperation* operation, std::string keyData) = 0;
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
  virtual std::string GetValue() = 0;
  virtual void FromValue(std::string data) = 0;
  virtual std::string GetTypeURL() = 0;
  virtual KeyMaterialType GetKeyMaterialType() = 0;
  virtual unsigned int GetVersion() = 0;
};

class Key {
public:
  virtual KeyID* GetKeyID() = 0;
  virtual KeyOperation* Operation() = 0;
  virtual KeyData* Data() = 0;
};
