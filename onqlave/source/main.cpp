#include <connection/client.h>
#include <connection/connection.h>
#include <encryption/encryption.h>
#include <fmt/core.h>
#include <keymanager/services/cprng_service.h>
#include <requests/requests.h>

int main() {
  Configuration config("arx-url", "arx-12345");

  connection conn(config, new hasher);

  int res = conn.Post("arx", new EncryptionOpenRequest);
  fmt::print("result: {}\n", res);

  Encryption enc;

  std::vector<unsigned char> c;
  std::vector<unsigned char> d;

  enc.Encrypt(c, d);
  enc.Decrypt(c, d);

  CPRNGService* service = new cprgnService();
  keyNs::Configuration kConf{.Cred{.AccessKey = "", .SigningKey = "", .SecretKey = ""},
                             .Retry{.Count = 0, .Valid = true},
                             .ArxURL = "http://localhost:8081/tenants/id/users/uid",
                             .Debug = false};

  keyManager km(kConf, service);
  std::vector<unsigned char> edk;
  km.FetchDecryptionKey(edk);
  km.FetchEncryptionKey();
}
