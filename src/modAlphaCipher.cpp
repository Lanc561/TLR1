#include "modAlphaCipher.h"
#include <iostream>
#include <locale>
#include <codecvt>

using namespace std;

// Конструктор
modAlphaCipher::modAlphaCipher(const std::wstring& skey)
{
    // Инициализация объединенного алфавита
    for(unsigned i = 0; i < numAlpha.size(); i++) {
        alphaNum[numAlpha[i]] = i;
    }
    key = convert(skey);
}

// Шифрование
std::wstring modAlphaCipher::encrypt(const std::wstring& open_text)
{
    std::vector<int> work = convert(open_text);
    for(unsigned i = 0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % numAlpha.size();
    }
    return convert(work);
}

// Дешифрование
std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text)
{
    std::vector<int> work = convert(cipher_text);
    for(unsigned i = 0; i < work.size(); i++) {
        work[i] = (work[i] + numAlpha.size() - key[i % key.size()]) % numAlpha.size();
    }
    return convert(work);
}

// Преобразование wstring -> vector<int>
std::vector<int> modAlphaCipher::convert(const std::wstring& s)
{
    std::vector<int> result;
    for(auto c : s) {
        // Проверка, что символ есть в алфавите
        if (alphaNum.find(c) != alphaNum.end()) {
            result.push_back(alphaNum[c]);
        }
    }
    return result;
}

// Преобразование vector<int> -> wstring
std::wstring modAlphaCipher::convert(const std::vector<int>& v)
{
    std::wstring result;
    for(auto i : v) {
        if (i >= 0 && i < numAlpha.size()) {
            result.push_back(numAlpha[i]);
        }
    }
    return result;
}