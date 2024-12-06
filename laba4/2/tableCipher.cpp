#include "TableCipher.h"
#include <algorithm>
#include <cctype>
#include <cwctype>

int TableCipher::getValidKey(const int& key)
{
    if (key <= 0)
        throw cipher_error("Invalid key");
    return key;
}

std::wstring TableCipher::getValidText(const std::wstring& text)
{
    if (text.empty())
        throw cipher_error("Empty text");

    std::wstring validText;
    for (auto c : text) {
        if (iswalpha(c)) {
            validText += towupper(c); // Приводим символ к верхнему регистру
        } else if (!iswspace(c) && !iswpunct(c)) {
            // Если символ не является буквой, пробелом или знаком препинания, 		 	выбрасываем исключение
            throw cipher_error("Invalid text");
        }
    }

    if (validText.empty())
        throw cipher_error("Invalid text");

    return validText;
}

TableCipher::TableCipher(const int& key)
    : key1(getValidKey(key)) {}

std::wstring TableCipher::encrypt(const std::wstring& encrypt_text)
{
    std::wstring validText = getValidText(encrypt_text);
    std::wstring tabl = validText; // создаем копию текста
    int dl, stroki, index, x;
    dl = validText.length(); // вычисляем длину сообщения
    stroki = (dl - 1) / key1 + 1;
    x = 0;
    for(int i = key1; i > 0; i--) { // проходим по столбцам в обратном порядке
        for(int j = 0; j < stroki; j++) {
            index = i + key1 * j; //Вычисляется индекс символа в сообщении,
            //который нужно взять из таблицы.
            if(index - 1 < dl) {
                tabl[x] = validText[index - 1];
                x++;
            }
        }
    }
    return tabl;
}

std::wstring TableCipher::decrypt(const std::wstring& decrypt_text)
{
    std::wstring validText = getValidText(decrypt_text);
    std::wstring tabl = validText;
    int dl, stroki, index, x;
    dl = validText.length();
    stroki = (dl - 1) / key1 + 1;
    x = 0;
    for(int i = key1; i > 0; i--) {
        for(int j = 0; j < stroki; j++) {
            index = i + key1 * j;
            if(index - 1 < dl) {
                tabl[index - 1] = validText[x];
                x++;
            }
        }
    }
    return tabl;
}
