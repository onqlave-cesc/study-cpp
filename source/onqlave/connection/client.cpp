#include <connection/client.h>
#include <contracts/requests/requests.h>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <iostream>


using  json = nlohmann::json;
struct OnqlaveEncryptErrorResponse {
  std::string status;
  std::string message;
  std::string correlation_id;
  std::vector<std::string> details;
  int64_t code;
};
struct  OQLResponse {
  OnqlaveEncryptErrorResponse error ;

};

const int HTTP_CODE_SUCCESS = 200;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
  size_t totalSize = size * nmemb;
  response->append(static_cast<char*>(contents), totalSize);
  return totalSize;
}

std::tuple<std::string, int> client::Post(std::string resource, OnqlaveRequest* body, std::map<std::string, std::string> headers) {
  CURL* curl= curl_easy_init();
  json reqData = json::parse(R"({})");
  if (const auto *decryptionBody = dynamic_cast<const DecryptionOpenRequest*>(body)) {
    reqData["edk"] = decryptionBody->EDK;
  }
  std::string bodyStr = reqData.dump();
  std::string responseData;
  long httpCode = 0;
  int responseCode = 0;
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, resource.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, bodyStr.c_str());

    struct curl_slist* cHeaders = nullptr;
    for (const auto& header: headers) {
      std::string headerStr = header.first + ": " + header.second;
      cHeaders = curl_slist_append(cHeaders, headerStr.c_str());
    }
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, cHeaders);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      responseCode = 1;
      std::cerr << "Failed to perform request: " << curl_easy_strerror(res) << std::endl;
    }
    curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &httpCode);
    if (httpCode != HTTP_CODE_SUCCESS) {
      responseCode = 1;
    }
   curl_easy_cleanup(curl);
  }
  return std::make_tuple(responseData, responseCode);
}

