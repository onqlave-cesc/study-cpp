#include <connection/client.h>
#include <connection/connection.h>
#include <fmt/core.h>
#include <requests/requests.h>

int main() {
  Configuration config("arx-url", "arx-12345");

  connection conn(config, new client, new hasher);

  int res = conn.Post("arx", new EncryptionOpenRequest);
  fmt::print("result: {}\n", res);
}
