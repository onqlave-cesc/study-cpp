#include <contracts/requests/requests.h>

int EncryptionOpenRequest::GetContent() { return 1; }

int DecryptionOpenRequest::GetContent() { return 0; }
