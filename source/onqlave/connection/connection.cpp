#include <connection/connection.h>
#include <requests/requests.h>

#include <fmt/format.h>

using namespace conNs;

const std::string OnqlaveAPIKey         = "ONQLAVE-API-KEY";
const std::string OnqlaveContent        = "Content-Type";
const std::string OnqlaveHost           = "ONQLAVE-HOST";
const std::string OnqlaveVersion        = "ONQLAVE-VERSION";
const std::string OnqlaveSignature      = "ONQLAVE-SIGANTURE";
const std::string OnqlaveDigest         = "ONQLAVE-DIGEST";
const std::string OnqlaveArx            = "ONQLAVE-ARX";
const std::string OnqlaveAgent          = "User-Agent";
const std::string OnqlaveRequestTime    = "ONQLAVE-REQUEST-TIME";
const std::string OnqlaveContentLength  = "ONQLAVE-CONTEXT-LEN";

const std::string ServerType        = "Onqlave/0.1";
const std::string Version           = "0.1";
const std::string Oonqlave_Content  = "application/json";

// TODO: SHOULD BE REMOVED LATER
const std::string placeholderHost = "https://gcp.community.serverless.au.dp0.onqlave.io";
const std::string arxID = "cluster--bNhVy8osXRrYtvXXbQlAW";
const std::string apiKey = "onq.elVTArNDjuLynflKi2PQEjMnsdyGAJiC";

int connection::Post(std::string resource, OnqlaveRequest *body) {
  std::map<std::string, std::string> headers;
  headers.insert({OnqlaveContent, Oonqlave_Content});
  headers.insert({OnqlaveAPIKey, apiKey});
  headers.insert({OnqlaveArx, arxID});
  headers.insert({OnqlaveHost, placeholderHost});
  headers.insert({OnqlaveAgent, ServerType});
  headers.insert({OnqlaveVersion, Version});

  std::string urlString = fmt::format("{}/{}", placeholderHost, resource);

  cl->Post(resource, body, headers);
  return 0;
}

connection::connection(Configuration configuration, Hasher *h): configuration(configuration), h(h) {
  Client *cl_ = new client();
  cl = cl_;
}
