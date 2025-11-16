#include "TableRouteCipher.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cctype>

// Конструктор
TableRouteCipher::TableRouteCipher(int key)
{
    columns = getValidKey(key);
}

// Метод шифрования
std::string TableRouteCipher::encrypt(const std::string& text)
{
    std::string validText = getValidText(text);
    
    // Проверка что текст БОЛЬШЕ ключа (количества столбцов)
    if (validText.length() <= columns) {
        throw cipher_error("Длина текста должна быть больше ключа (количества столбцов)");
    }
    
    size_t original_length = validText.size();
    size_t rows = (original_length + columns - 1) / columns;

    std::vector<std::vector<char>> table(rows, std::vector<char>(columns, ' '));
    size_t index = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            if (index < original_length) {
                table[i][j] = validText[index++];
            }
        }
    }

    std::string result;
    for (size_t j = columns; j > 0; j--) {
        for (size_t i = 0; i < rows; i++) {
            if (table[i][j-1] != ' ') {
                result += table[i][j-1];
            }
        }
    }
    return result;
}

// Метод дешифрования
std::string TableRouteCipher::decrypt(const std::string& text)
{
    std::string validText = getValidText(text);
    
    // Проверка что текст БОЛЬШЕ ключа (количества столбцов)
    if (validText.length() <= columns) {
        throw cipher_error("Длина текста должна быть больше ключа (количества столбцов)");
    }
    
    size_t encrypted_length = validText.size();
    size_t rows = (encrypted_length + columns - 1) / columns;

    size_t original_length = encrypted_length;
    std::vector<std::vector<char>> table(rows, std::vector<char>(columns, ' '));
    std::vector<std::vector<bool>> filled(rows, std::vector<bool>(columns, false));

    size_t original_index = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            if (original_index < original_length) {
                filled[i][j] = true;
                original_index++;
            }
        }
    }

    size_t encrypted_index = 0;
    for (size_t j = columns; j > 0; j--) {
        for (size_t i = 0; i < rows; i++) {
            if (filled[i][j-1] && encrypted_index < encrypted_length) {
                table[i][j-1] = validText[encrypted_index++];
            }
        }
    }

    std::string result;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            if (filled[i][j]) {
                result += table[i][j];
            }
        }
    }
    return result;
}

// Валидация ключа
size_t TableRouteCipher::getValidKey(int key)
{
    if (key <= 0) {
        throw cipher_error("Ключ должен быть положительным");
    }
    return static_cast<size_t>(key);
}

// Валидация текста
std::string TableRouteCipher::getValidText(const std::string& text)
{
    if (text.empty()) {
        throw cipher_error("Текст пуст");
    }
    std::string result;
    for (char c : text) {
        if (isalpha(c)) {
            result += toupper(c);
        }
    }
    if (result.empty()) {
        throw cipher_error("Текст не содержит букв");
    }
    return result;
}
