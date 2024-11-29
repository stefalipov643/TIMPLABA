#include <iostream>
#include "transposition_cipher.h"

void testTranspositionCipher() {
    TranspositionCipher cipher("2143"); // Ключ для перестановки

    // Тест 1: обычный текст
    std::string plaintext = "HI STEF SHEF";
    std::string encrypted = cipher.encrypt(plaintext);
    std::string decrypted = cipher.decrypt(encrypted);
    
    std::cout << "Test 1 - Normal Text" << std::endl;
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
    std::cout << "Test Passed: " << (plaintext == decrypted) << std::endl;

    // Тест 2: текст с пробелами и символами
    plaintext = "HI, STEF SHEF!";
    encrypted = cipher.encrypt(plaintext);
    decrypted = cipher.decrypt(encrypted);
    
    std::cout << "Test 2 - Text with Special Characters" << std::endl;
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
    std::cout << "Test Passed: " << (plaintext == decrypted) << std::endl;

    // Тест 3: пустой текст
    plaintext = "";
    encrypted = cipher.encrypt(plaintext);
    decrypted = cipher.decrypt(encrypted);
    
    std::cout << "Test 3 - Empty Text" << std::endl;
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
    std::cout << "Test Passed: " << (plaintext == decrypted) << std::endl;
}

int main() {
    testTranspositionCipher();
    return 0;
}
