#pragma once

#include <connection/client.h>
#include <keymanager/key_manager_client.h>
#include <credential/credential.h>

#include <string>

const std::string INVALID_ARX = "invalid_arx";

class Option {
public:
  virtual void apply(keyNs::Configuration config) = 0;
};

class credentialOption : public Option {
public:
  credNs::Credential cred;
  void apply(keyNs::Configuration config);
};

class retryOption : public Option {
public:
  RetrySetting retry;
  void apply(keyNs::Configuration config);
};

class arxOption : public Option {
public:
  std::string arxURL;
  void apply(keyNs::Configuration config);
};

class debugOption : public Option {
public:
  bool debug;
  void apply(keyNs::Configuration config);
};

Option* WithCredential(credNs::Credential c);
Option* WithRetry(RetrySetting r);
Option* WithDebug(bool debug);
Option* WithArx(std::string a);
