#include <connection/client.h>
#include <connection/connection.h>
#include <encryption/encryption.h>
#include <fmt/core.h>
#include <keymanager/services/cprng_service.h>
#include <contracts/requests/requests.h>

#include <vector>
#include <iostream>
#include <fmt/core.h>
#include <keymanager/primitives/xchacha20_poly1305_aead.h>

#define MESSAGE (const unsigned char *) "test"
#define MESSAGE_LEN 4
#define ADDITIONAL_DATA (const unsigned char *) "123456"
#define ADDITIONAL_DATA_LEN 6

int main() {
//  Configuration config{.ArxUrl = "tenants/arx/arx-12345", .ArxID = "arx-12345"};
//
//  connection conn(config, new hasher);
//
//  std::vector<Option*> opts;
//  Option* retryOpt = WithRetry(RetrySetting{
//      .Count=2,
//      .WaitTime=400,
//      .MaxWaitTime=200
//  });
//  Option* arxOpt = WithArx("tenants/arx/arx-12345");
//  Option* debugOpt = WithDebug(true);
//  Option* credOpt = WithCredential(credNs::Credential{
//      .AccessKey="accKey",
//      .SigningKey="signKey",
//      .SecretKey="secKey"
//  });
//
//  opts.push_back(retryOpt);
//  opts.push_back(arxOpt);
//  opts.push_back(debugOpt);
//  opts.push_back(credOpt);
//
//  Encryption enc = Encryption(opts);
//
//  std::vector<unsigned char> c;
//  std::vector<unsigned char> d;
//
//  enc.Encrypt(c, d);
//  enc.Decrypt(c, d);


  unsigned char ct;
  unsigned long long ct_len;
  XChaCha20Poly1305AEAD xchacha = XChaCha20Poly1305AEAD(nullptr, nullptr);
  xchacha.Encrypt(nullptr,nullptr, ct, ct_len);

  //std::string str = std::string(reinterpret_cast<const char*>(ct), MESSAGE_LEN);
  std::cout << "CIPHER: " << ct_len << std::endl;

  xchacha.Decrypt(ct, reinterpret_cast<const unsigned char*>("associatedata"));
}
