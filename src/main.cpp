#include <iostream>
#include <locale>
#include <codecvt>
#include "modAlphaCipher.h"

using namespace std;

// Функция для проверки работы шифра
void check(const wstring& text, const wstring& key, const wstring& testName)
{
    wstring cipherText;
    wstring decryptedText;
    
    try {
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(text);
        decryptedText = cipher.decrypt(cipherText);
        
        wcout << L"=== " << testName << L" ===" << endl;
        wcout << L"Ключ: " << key << endl;
        wcout << L"Исходный текст: " << text << endl;
        wcout << L"Зашифрованный: " << cipherText << endl;
        wcout << L"Расшифрованный: " << decryptedText << endl;
        
        if (text == decryptedText)
            wcout << L"✓ Тест пройден\n";
        else
            wcout << L"✗ Ошибка!\n";
            
    } catch (const exception& e) {
        wcout << L"Ошибка: " << e.what() << endl;
    }
    wcout << endl;
}

int main()
{
    // Установка локали для поддержки русского и английского языков
    setlocale(LC_ALL, "en_US.UTF-8");
    locale::global(locale("en_US.UTF-8"));
    wcout.imbue(locale("en_US.UTF-8"));
    
    wcout << L"ТЕСТИРОВАНИЕ ШИФРА С ПОДДЕРЖКОЙ РУССКОГО И АНГЛИЙСКОГО ЯЗЫКОВ" << endl;
    wcout << L"=============================================================" << endl;
    
    // Тесты на русском языке
    check(L"ПРИВЕТМИР", L"КЛЮЧ", L"Русский текст 1");
    check(L"ПРОГРАММИРОВАНИЕ", L"ШИФР", L"Русский текст 2");
    check(L"КОДИРОВАНИЕТЕКСТА", L"АБВГ", L"Русский текст 3");
    
    // Тесты на английском языке
    check(L"HELLOWORLD", L"KEY", L"Английский текст 1");
    check(L"PROGRAMMING", L"CODE", L"Английский текст 2");
    check(L"ENCRYPTIONTEST", L"ABCD", L"Английский текст 3");

    
    wcout << L"Алфавит системы: " << endl;
    wcout << L"Английские буквы: ABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
    wcout << L"Русские буквы: АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ" << endl;
    
    return 0;
}