#include <connection/connection.h>
#include <requests/requests.h>
#include <fmt/core.h>

int connection::Post(std::string resource, OnqlaveRequest *body) { 
    fmt::print("resource {}\n", resource);
    fmt::print("config arx id {}\n", configuration.ArxID);
    fmt::print("config arx url {}\n", configuration.ArxUrl);
    return 0; 
    }

connection::connection(Configuration configuration, Client *cl, Hasher *h): configuration(configuration), cl(cl), h(h) {}

Configuration::Configuration(std::string arxUrl, std::string arxID)
    : ArxUrl(arxUrl), ArxID(arxID) {}
