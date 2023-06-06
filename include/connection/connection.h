#pragma once

#include <client.h>
#include <requests/requests.h>
#include <utils/hasher.h>

#include <string>

class Connection {
  virtual int Post(std::string resource, const OnqlaveRequest& body) = 0;
};

class connection : Connection {
private:
  Configuration configuration;
  Client& cl;
  Hasher& h;

public:
  connection(Configuration configuration, Client& cl, Hasher& h);
  int Post(std::string resource, const OnqlaveRequest& body) override;
};

class Configuration {
public:
  std::string ArxUrl;
  std::string ArxID;

  Configuration(std::string arxUrl, std::string arxID);
};
