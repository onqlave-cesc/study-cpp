#pragma once

#include <connection/client.h>
#include <credential/credential.h>
#include <requests/requests.h>
#include <utils/hasher.h>

#include <string>

class Connection {
  virtual int Post(std::string resource, OnqlaveRequest *body) = 0;
};

namespace conNs {
  class Configuration {
  public:
    Credential Cred;
    RetrySetting Retry;
    std::string ArxUrl;
    std::string ArxID;

    Configuration(std::string arxUrl, std::string arxID);
  };
}  // namespace connection

using namespace conNs;

class connection : public Connection {
private:
  Configuration configuration;
  Client *cl;
  Hasher *h;

public:
  connection(Configuration configuration, Client *cl, Hasher *h);
  int Post(std::string resource, OnqlaveRequest *body) override;
};
