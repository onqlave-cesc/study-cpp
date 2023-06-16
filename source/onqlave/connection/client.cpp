#include <connection/client.h>
#include <requests/requests.h>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <iostream>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
  size_t totalSize = size * nmemb;
  response->append(static_cast<char*>(contents), totalSize);
  return totalSize;
}

int client::Post(std::string resource, OnqlaveRequest* body, std::map<std::string, std::string> headers) {
  CURL* curl= curl_easy_init();

  nlohmann::json reqData;
  std::string bodystr = reqData.dump();
  std::string responseData;
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, resource.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, bodystr.c_str());

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
      std::cerr << "Failed to perform request: " << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
    std::cout << "=================== RESPONSE: " << responseData << std::endl;

    // TODO: need to review
//    nlohmann::json resData = nlohmann::json::parse(responseData);
//    auto arxData = resData["data"].template get<reqData::ArxRequest>();
  }
  return 0;
}
