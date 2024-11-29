#include "transposition_cipher.h"
#include <algorithm>
#include <cmath>
#include <vector>

TranspositionCipher::TranspositionCipher(const std::string& key) : key(key) {}

std::string TranspositionCipher::encrypt(const std::string& plaintext) {
    int col = key.length();
    int row = std::ceil(static_cast<double>(plaintext.length()) / col);
    std::vector<std::vector<char>> grid(row, std::vector<char>(col, ' '));

    // Заполнение таблицы
    for (size_t i = 0; i < plaintext.length(); ++i) {
        grid[i / col][i % col] = plaintext[i];
    }

    // Генерация зашифрованного текста
    std::string ciphertext;
    for (size_t i = 0; i < col; ++i) {
        for (size_t j = 0; j < row; ++j) {
            ciphertext += grid[j][i];
        }
    }
    return ciphertext;
}

std::string TranspositionCipher::decrypt(const std::string& ciphertext) {
    int col = key.length();
    int row = std::ceil(static_cast<double>(ciphertext.length()) / col);
    std::vector<std::vector<char>> grid(row, std::vector<char>(col, ' '));

    // Заполнение таблицы по столбцам
    int index = 0;
    for (size_t i = 0; i < col; ++i) {
        for (size_t j = 0; j < row; ++j) {
            if (index < ciphertext.length())
                grid[j][i] = ciphertext[index++];
        }
    }

    // Генерация декодированного текста
    std::string plaintext;
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            plaintext += grid[i][j];
        }
    }
    return plaintext;
}
