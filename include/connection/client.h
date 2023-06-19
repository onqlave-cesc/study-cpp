#pragma once

#include <requests/requests.h>

#include <map>
#include <string>
#include <tuple>

class Client {
public:
  virtual std::tuple<std::string, int> Post(std::string resource, OnqlaveRequest* body, std::map<std::string, std::string> headers) = 0;
};

class client : public Client {
  public:
    std::tuple<std::string, int> Post(std::string resource, OnqlaveRequest* body, std::map<std::string, std::string> headers);
};

class RetrySetting {
public:
  int Count;
  int WaitTime;
  int MaxWaitTime;

  void Valid();
};
