#include "TableRouteCipher.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cctype> // Для toupper

// Конструктор
TableRouteCipher::TableRouteCipher(int key)
{
    columns = getValidKey(key);
}

// Метод шифрования
std::string TableRouteCipher::encrypt(const std::string& text)
{
    std::string validText = getValidText(text);
    int original_length = validText.size();
    int rows = (original_length + columns - 1) / columns;
    int total_cells = rows * columns;

    std::vector<std::vector<char>> table(rows, std::vector<char>(columns, ' '));
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (index < original_length) {
                table[i][j] = validText[index++];
            }
        }
    }

    std::string result;
    for (int j = columns - 1; j >= 0; j--) {
        for (int i = 0; i < rows; i++) {
            if (table[i][j] != ' ') {
                result += table[i][j];
            }
        }
    }
    return result;
}

// Метод дешифрования
std::string TableRouteCipher::decrypt(const std::string& text)
{
    std::string validText = getValidText(text);
    int encrypted_length = validText.size();
    int rows = (encrypted_length + columns - 1) / columns;

    int original_length = encrypted_length;
    std::vector<std::vector<char>> table(rows, std::vector<char>(columns, ' '));
    std::vector<std::vector<bool>> filled(rows, std::vector<bool>(columns, false));

    int original_index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (original_index < original_length) {
                filled[i][j] = true;
                original_index++;
            }
        }
    }

    int encrypted_index = 0;
    for (int j = columns - 1; j >= 0; j--) {
        for (int i = 0; i < rows; i++) {
            if (filled[i][j] && encrypted_index < encrypted_length) {
                table[i][j] = validText[encrypted_index++];
            }
        }
    }

    std::string result;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (filled[i][j]) {
                result += table[i][j];
            }
        }
    }
    return result;
}

// Валидация ключа
int TableRouteCipher::getValidKey(int key)
{
    if (key <= 0) {
        throw std::invalid_argument("Ключ должен быть положительным");
    }
    return key;
}

// Валидация текста
std::string TableRouteCipher::getValidText(const std::string& text)
{
    if (text.empty()) {
        throw std::invalid_argument("Текст пуст");
    }
    std::string result;
    for (char c : text) {
        if (isalpha(c)) {
            result += toupper(c);
        }
    }
    if (result.empty()) {
        throw std::invalid_argument("Текст не содержит букв");
    }
    return result;
}
