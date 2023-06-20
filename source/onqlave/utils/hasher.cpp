#include <contracts/requests/requests.h>
#include <utils/hasher.h>

#include <map>
#include <string>

std::string hasher::Digest(const OnqlaveRequest& body) { return ""; }

std::string hasher::Sign(std::map<std::string, std::string>) { return ""; }
