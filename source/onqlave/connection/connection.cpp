#include <connection/connection.h>
#include <fmt/core.h>
#include <requests/requests.h>

using namespace conNs;

int connection::Post(std::string resource, OnqlaveRequest *body) {
  fmt::print("resource {}\n", resource);
  fmt::print("config arx id {}\n", configuration.ArxID);
  fmt::print("config arx url {}\n", configuration.ArxUrl);
  return 0;
}

connection::connection(Configuration configuration, Hasher *h)
    : configuration(configuration), cl(cl), h(h) {}
