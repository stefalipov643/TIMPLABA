#ifndef TRANSPOSITION_CIPHER_H
#define TRANSPOSITION_CIPHER_H

#include <string>

class TranspositionCipher {
public:  TranspositionCipher(const std::string& key);
    std::string encrypt(const std::string& plaintext);
    std::string decrypt(const std::string& ciphertext);

private:
    std::string key;
};

#endif // TRANSPOSITION_CIPHER_H
