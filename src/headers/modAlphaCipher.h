#pragma once
#include <map>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>

class modAlphaCipher
{
private:
    std::wstring numAlpha = L"ABCDEFGHIJKLMNOPQRSTUVWXYZАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; // объединенный алфавит
    std::map<wchar_t, int> alphaNum; // ассоциативный массив "номер по символу"
    std::vector<int> key;    // КЛЮЧ
    std::vector<int> convert(const std::wstring& s); // преобразование строка-вектор
    std::wstring convert(const std::vector<int>& v); // преобразование вектор-строка
public:
    modAlphaCipher() = delete;
    modAlphaCipher(const std::wstring& skey);    // конструктор для установки ключа
    std::wstring encrypt(const std::wstring& open_text);    // зашифрование
    std::wstring decrypt(const std::wstring& cipher_text); // расшифрование
};