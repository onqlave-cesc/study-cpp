#include <connection/client.h>
#include <requests/requests.h>
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

int client::Post(std::string resource, OnqlaveRequest* body, std::map<std::string, std::string> headers) {
  CURL* curl= curl_easy_init();


  std::string bodystr = reqData.dump();
  std::string responseData;
  long http_code = 0;
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
    curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &http_code);
    json resDataJson = json::parse(responseData);
    std::cout << "===========Parse Data Response============"<< std::endl << resDataJson<< std::endl;
    if (http_code != HTTP_CODE_SUCCESS) {
      OQLResponse oqlResponse;
      oqlResponse.error.status = resDataJson["error"]["status"];
      oqlResponse.error.message = resDataJson["error"]["message"];
      std::cout << "Data parse Json 2: " << oqlResponse.error.message << std::endl;
//      OnqlaveEncryptFailedResponse responseFailed;
//      responseFailed.status = resDataJson["erorr"]["status"];
//      responseFailed.message = resDataJson["erorr"]["message"];
//      std::cout << "Message: " << responseFailed.message << std::endl;
    }else{

    }





    // TODO: need to review nlohmann::json resData = nlohmann::json::parse(responseData);
//    auto arxData = resData["data"].template get<reqData::ArxRequest>();

   curl_easy_cleanup(curl);
  }
  return 0;
}

