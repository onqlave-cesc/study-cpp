#include <connection/client.h>
#include <connection/connection.h>
#include <credential/credential.h>
#include <encryption/options.h>

#include <string>

void credentialOption::apply(keyNs::Configuration& c) { c.Cred = cred; }

void retryOption::apply(keyNs::Configuration& c) { c.Retry = retry; }

void arxOption::apply(keyNs::Configuration& c) { c.ArxURL = arxURL; }

void debugOption::apply(keyNs::Configuration& c) { c.Debug = debug; }

Option* WithCredential(credNs::Credential c) {
  auto* opt = new credentialOption();
  opt->cred = c;
  return opt;
}

Option* WithRetry(RetrySetting r) {
  auto* opt = new retryOption();
  opt->retry = r;
  return opt;
}

Option* WithDebug(bool debug) {
  auto* opt = new debugOption();
  opt->debug = debug;
  return opt;
}

Option* WithArx(std::string a) {
  auto* opt = new arxOption();
  opt->arxURL = a;
  return opt;
}
