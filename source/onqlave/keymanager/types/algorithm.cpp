#include <keymanager/types/algorithm.h>

algorithm::algorithm(unsigned int version_, unsigned int algo_, std::string key_) : version(version_), algo(algo_), key(key_) {}

std::string algorithm::Serialise() {
  return "";
}

int algorithm::Deserialise(std::string buffer) {
  return 0;
}

std::string algorithm::Key() {
  return "";
}

int algorithm::Version() {
  return version;
}

std::string algorithm::Algorithm() {
  return "algo";
}
