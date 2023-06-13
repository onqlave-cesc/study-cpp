#include <connection/client.h>
#include <requests/requests.h>
#include <curl/curl.h>

#include <iostream>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
  size_t totalSize = size * nmemb;
  response->append(static_cast<char*>(contents), totalSize);
  return totalSize;
}

int client::Post(std::string resource, OnqlaveRequest* body, std::map<std::string, std::string> headers) {
  std::string response;
  CURL* curl= curl_easy_init();

  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, resource.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      std::cerr << "Failed to perform request: " << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
  }

  std::cout << "============= response:" << response << std::endl;
  return 0;
}
