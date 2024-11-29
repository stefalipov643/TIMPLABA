#ifndef GRONSFELD_CIPHER_H
#define GRONSFELD_CIPHER_H

#include <string>

class GronsfeldCipher {
public:
    GronsfeldCipher(const std::string& key);
    std::string encrypt(const std::string& plaintext);
    std::string decrypt(const std::string& ciphertext);

private:
    std::string key;
};

#endif // GRONSFELD_CIPHER_H
