#include <connection/client.h>
#include <connection/connection.h>
#include <encryption/encryption.h>
#include <fmt/core.h>
#include <requests/requests.h>

int main() {
  Configuration config("arx-url", "arx-12345");

  connection conn(config, new client, new hasher);

  int res = conn.Post("arx", new EncryptionOpenRequest);
  fmt::print("result: {}\n", res);

  Encryption enc;

  std::vector<unsigned char> c;
  std::vector<unsigned char> d;

  enc.Encrypt(c, d);
  enc.Decrypt(c, d);
}
