#pragma once

#include <requests/requests.h>

#include <map>
#include <string>

class Client {
  virtual int Post(std::string resource, const OnqlaveRequest& body, std::map<std::string, std::string> headers) = 0;
};

class client : public Client {
  public:
    int Post(std::string resource, const OnqlaveRequest& body, std::map<std::string, std::string> headers);
};

class RetrySetting {
public:
  int Count;
  int WaitTime;
  int MaxWaitTime;

  void Valid();
};
