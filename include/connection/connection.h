#pragma once

#include <connection/client.h>
#include <requests/requests.h>
#include <utils/hasher.h>

#include <tuple>
#include <string>

class Connection {
public:
  virtual std::tuple<std::string, int> Post(std::string resource, OnqlaveRequest *body) = 0;
};

namespace conNs {
  struct Credential {
    std::string AccessKey;
    std::string SigningKey;
  };

  struct Configuration {
    Credential Cred;
    RetrySetting Retry;
    std::string ArxUrl;
    std::string ArxID;
  };

}  // namespace conNs

using namespace conNs;

class connection : public Connection {
private:
  Configuration configuration;
  Client *cl;
  Hasher *h;

public:
  connection(Configuration configuration, Hasher *h);
  std::tuple<std::string, int> Post(std::string resource, OnqlaveRequest *body) override;
};
