#include "gronsfeld_cipher.h"

GronsfeldCipher::GronsfeldCipher(const std::string& key) : key(key) {}

std::string GronsfeldCipher::encrypt(const std::string& plaintext) {
    std::string ciphertext;
    for (size_t i = 0; i < plaintext.length(); ++i) {
        char p = plaintext[i];
        int k = key[i % key.length()] - '0'; // Ключ как цифра
        
        if (isalpha(p)) {
            char base = isupper(p) ? 'A' : 'a'; // Базовый символ
            ciphertext += (p - base + k) % 26 + base;
        } else {
            ciphertext += p; // Оставляем символ как есть
        }
    }
    return ciphertext;
}

std::string GronsfeldCipher::decrypt(const std::string& ciphertext) {
    std::string plaintext;
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        char c = ciphertext[i];
        int k = key[i % key.length()] - '0';

        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            plaintext += (c - base - k + 26) % 26 + base; // + 26 для обработки отрицательных значений
        } else {
            plaintext += c; // Оставляем символ как есть
        }
    }
    return plaintext;
}
