#include <connection/client.h>
#include <requests/requests.h>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <vector>

namespace reqData {
  struct ArxRequest {
    std::string id;
    std::string name;
    std::string tenant_id;
    std::string owner;
    int spend_limit;
    std::string purpose;
    std::string plan;
    std::string encryption_method;
    int rotation_cycle;
    std::string provider;
    std::string master_key;
    std::string wrapping_key_store;
    std::vector<std::string> regions;
  };
  
  void to_json(nlohmann::json& j, const ArxRequest& r) {
    j = nlohmann::json{
        {"id", r.id},
        {"name", r.name},
        {"tenant_id", r.tenant_id},
        {"owner", r.owner},
        {"spend_limit", r.spend_limit},
        {"purpose", r.purpose},
        {"plan", r.plan},
        {"encryption_method", r.encryption_method},
        {"rotation_cycle", r.rotation_cycle},
        {"provider", r.provider},
        {"master_key", r.master_key},
        {"wrapping_key_store", r.wrapping_key_store},
        {"regions", r.regions}
    };
  }

  void from_json(const nlohmann::json& j, ArxRequest& p) {
    j.at("id").get_to(p.id);
    j.at("name").get_to(p.name);
    j.at("owner").get_to(p.owner);
    j.at("spend_limit").get_to(p.spend_limit);
    j.at("purpose").get_to(p.purpose);
    j.at("plan").get_to(p.plan);
    j.at("encryption_method").get_to(p.encryption_method);
    j.at("rotation_cycle").get_to(p.rotation_cycle);
    j.at("provider").get_to(p.provider);
    j.at("regions").get_to(p.regions);
  }
} // namespace reqData

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
  size_t totalSize = size * nmemb;
  response->append(static_cast<char*>(contents), totalSize);
  return totalSize;
}

int client::Post(std::string resource, OnqlaveRequest* body, std::map<std::string, std::string> headers) {
  CURL* curl= curl_easy_init();

  reqData::ArxRequest req = {
    .id= "cluster--111111111111111111",
    .name= "arx-kkk",
    .tenant_id= "tenant--Is2tYXUJOt8tjvVNt1Qa1",
    .owner= "m.mahdiyeh@gmail.com",
    .spend_limit= 10,
    .purpose= "development",
    .plan= "serverless",
    .encryption_method= "aes-gcm-128",
    .rotation_cycle= 2592000,
    .provider= "gcp",
    .master_key= "mk",
    .wrapping_key_store="wks",
    .regions= std::vector<std::string>{"au"}
  };

  nlohmann::json reqData;
  reqData["arx"] = req;

  std::string bodystr = reqData.dump();
  std::string responseData;
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, resource.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, bodystr.c_str());

    struct curl_slist* cHeaders = nullptr;
    cHeaders = curl_slist_append(cHeaders, headers["content_type"].c_str());
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
