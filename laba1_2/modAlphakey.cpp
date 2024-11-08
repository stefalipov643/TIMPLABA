#include "modAlphakey.h"

std::wstring modAlphakey::encrypt(const std::wstring& open_text)
{
    std::wstring tabl(open_text.length(), L' '); 
    int dl = open_text.length();
    int nstrok = (dl - 1) / key1 + 1; 
    int x = 0;

    for(int i = key1; i > 0; i--) { 
        for(int j = 0; j < nstrok; j++) { 
            int index = i + key1 * j;
            if(index - 1 < dl) {
                tabl[x] = open_text[index - 1];
                x++;
            }
        }
    }
    return tabl;
}

std::wstring modAlphakey::decrypt(const std::wstring& cipher_text)
{
    std::wstring tabl(cipher_text.length(), L' '); 
    int dl = cipher_text.length();
    int nstrok = (dl - 1) / key1 + 1; 
    int x = 0;

    for(int i = key1; i > 0; i--) { 
        for(int j = 0; j < nstrok; j++) { 
            int index = i + key1 * j;
            if(index - 1 < dl) {
                tabl[index - 1] = cipher_text[x++];
            }
        }
    }
    return tabl;
}
