#pragma once

#include <string>
#include <vector>

typedef int HashType;

const HashType HashTypeUNKNOWNHASH = 0;
const HashType HashTypeSHA1 = 1;
const HashType HashTypeSHA384 = 2;
const HashType HashTypeSHA256 = 3;
const HashType HashTypeSHA512 = 4;
const HashType HashTypeSHA224 = 5;

class Key;
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
                                       std::vector<unsigned char> byte) = 0;
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
