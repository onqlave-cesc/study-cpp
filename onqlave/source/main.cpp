#include <connection/client.h>
#include <connection/connection.h>
#include <encryption/encryption.h>
#include <fmt/core.h>
#include <keymanager/services/cprng_service.h>
#include <requests/requests.h>

#include <vector>
#include <fmt/core.h>

int main() {
  Configuration config{.ArxUrl = "tenants/arx/arx-12345", .ArxID = "arx-12345"};

  connection conn(config, new hasher);

  std::vector<Option*> opts;
  Option* retryOpt = WithRetry(RetrySetting{
      .Count=2,
      .WaitTime=400,
      .MaxWaitTime=200
  });
  Option* arxOpt = WithArx("tenants/arx/arx-12345");
  Option* debugOpt = WithDebug(true);
  Option* credOpt = WithCredential(credNs::Credential{
      .AccessKey="accKey",
      .SigningKey="signKey",
      .SecretKey="secKey"
  });

  opts.push_back(retryOpt);
  opts.push_back(arxOpt);
  opts.push_back(debugOpt);
  opts.push_back(credOpt);

  Encryption enc = Encryption(opts);

  std::vector<unsigned char> c;
  std::vector<unsigned char> d;

  enc.Encrypt(c, d);
//  enc.Decrypt(c, d);
}
