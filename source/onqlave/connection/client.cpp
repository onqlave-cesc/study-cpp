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

  nlohmann::json ex1 = nlohmann::json::parse(R"(
{
  "arx": {
        "id": "cluster--111111111111111111",
        "name": "arx-kkk",
        "tenant_id": "tenant--Is2tYXUJOt8tjvVNt1Qa1",
        "owner": "m.mahdiyeh@gmail.com",
        "spend_limit": 10,
        "purpose": "development",
        "plan": "serverless",
        "encryption_method": "aes-gcm-128",
        "rotation_cycle": 2592000,
        "provider": "gcp",
        "master_key": "mk",
        "wrapping_key_store":"wks",
        "regions": ["au"]
      }
}
)");

  std::string bodystr = ex1.dump();

  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, resource.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, bodystr.c_str());

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      std::cerr << "Failed to perform request: " << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
  }
  return 0;
}
