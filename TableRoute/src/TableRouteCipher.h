#pragma once
#include <string>
#include <vector>

class TableRouteCipher // ← Убедись, что имя класса здесь TableRouteCipher
{
private:
    int columns;
    int getValidKey(int key);
    std::string getValidText(const std::string& text); // ← std::string, а не wstring

public:
    TableRouteCipher() = delete;
    TableRouteCipher(int key);
    std::string encrypt(const std::string& text);   // ← std::string
    std::string decrypt(const std::string& text);   // ← std::string
};
