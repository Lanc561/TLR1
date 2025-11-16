#pragma once
#include <string>
#include <vector>
#include <stdexcept>

class cipher_error : public std::invalid_argument {
public:
    explicit cipher_error(const std::string& what_arg) : 
        std::invalid_argument(what_arg) {}
    explicit cipher_error(const char* what_arg) : 
        std::invalid_argument(what_arg) {}
};

class TableRouteCipher
{
private:
    size_t columns; // меняем на size_t
    size_t getValidKey(int key); // меняем возвращаемый тип
    std::string getValidText(const std::string& text);
    
public:
    TableRouteCipher() = delete;
    TableRouteCipher(int key);
    std::string encrypt(const std::string& text);
    std::string decrypt(const std::string& text);
};
