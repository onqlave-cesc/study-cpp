#include <connection/connection.h>
#include <requests/requests.h>
#include <fmt/format.h>
#include <iostream>

using namespace conNs;

const std::string OnqlaveAPIKey         = "ONQLAVE-API-KEY";
const std::string OnqlaveContent        = "Content-Type";
const std::string OnqlaveHost           = "ONQLAVE-HOST";
const std::string OnqlaveVersion        = "ONQLAVE-VERSION";
const std::string OnqlaveSignature      = "ONQLAVE-SIGNATURE";
const std::string OnqlaveDigest         = "ONQLAVE-DIGEST";
const std::string OnqlaveArx            = "ONQLAVE-ARX";
const std::string OnqlaveAgent          = "User-Agent";
const std::string OnqlaveRequestTime    = "ONQLAVE-REQUEST-TIME";
const std::string OnqlaveContentLength  = "ONQLAVE-CONTEXT-LEN";

const std::string ServerType        = "Onqlave/0.1";
const std::string Version           = "0.1";
const std::string Onqlave_Content  = "application/json";
const std::string Onqlave_Request_Time = "1686905875";
const std::string Onqlave_Content_Length = "2";
const std::string DigestTemplate = "SHA512=J8dGcK23UHX60FjVzq97IMTneGyDuuijL2Jvl4KvNMmjPCBG72D9Knh403jin+yFGAa72aZ4ePOp8c2kgwdj/Q==";
const std::string SignatureTemplate = "HMAC-SHA512=XH0+0kwCR78WWwM/1FPSHEnHbIiZXWeyXjqB22hvRfeWzfuTKubIVp8gW7HYpCItMi1TRTopyWurrJPFFP3NNQ==";

// TODO: SHOULD BE REMOVED LATER
const std::string placeholderHost = "https://gcp.community.serverless.au.dp0.onqlave.io";
const std::string arxID = "cluster--bNhVy8osXRrYtvXXbQlAW";
const std::string apiKey = "onq.elVTArNDjuLynflKi2PQEjMnsdyGAJiC";

int connection::Post(std::string resource, OnqlaveRequest *body) {
  std::map<std::string, std::string> headers;
  headers.insert({OnqlaveContent, Onqlave_Content});
  headers.insert({OnqlaveAPIKey, apiKey});
  headers.insert({OnqlaveArx, arxID});
  headers.insert({OnqlaveHost, placeholderHost});
  headers.insert({OnqlaveAgent, ServerType});
  headers.insert({OnqlaveVersion, Version});
  headers.insert({OnqlaveRequestTime, Onqlave_Request_Time});
  headers.insert({OnqlaveContentLength, Onqlave_Content_Length});
  headers.insert({OnqlaveDigest, DigestTemplate});
  headers.insert({OnqlaveSignature, SignatureTemplate});

  for (auto  const &pair: headers){
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  std::string urlString = fmt::format("{}/{}", placeholderHost, resource);
  cl->Post(urlString, body, headers);
  return 0;
}

connection::connection(Configuration configuration, Hasher *h): configuration(configuration), h(h) {
  Client *cl_ = new client();
  cl = cl_;
}
