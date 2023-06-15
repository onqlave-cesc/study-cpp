#include <connection/connection.h>
#include <requests/requests.h>

using namespace conNs;

int connection::Post(std::string resource, OnqlaveRequest *body) {
  std::map<std::string, std::string> headers;
  headers.insert({"content_type", "Content-Type: application/json"});
  cl->Post(resource, body, headers);
  return 0;
}

connection::connection(Configuration configuration, Hasher *h): configuration(configuration), h(h) {
  Client *cl_ = new client();
  cl = cl_;
}
