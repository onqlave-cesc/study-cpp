#include <connection/connection.h>
#include <connection/client.h>
#include <fmt/fmt.h>

int main() {
  Configuration c = Configuration("arx-url", "arx-12345");
  Client* cl;
  Hasher* h;
  connection* conn = new connection(c, cl, h);

  int res = conn->Post("arx", nullptr);
  fmt::print(res);
}