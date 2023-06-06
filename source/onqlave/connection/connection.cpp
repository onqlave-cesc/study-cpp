#include <connection/connection.h>
#include <requests/requests.h>

int connection::Post(std::string resource, const OnqlaveRequest& body) { return 0; }

connection::connection(Configuration configuration, Client& cl, Hasher& h): configuration(configuration), cl(cl), h(h) {}

Configuration::Configuration(std::string arxUrl, std::string arxID)
    : ArxUrl(arxUrl), ArxID(arxID) {}
