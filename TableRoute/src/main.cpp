// main.cpp
#include <iostream>
#include "TableRouteCipher.h"

int main()
{
    try {
        int key;
        std::cout << "Введите ключ (число столбцов): ";
        std::cin >> key;

        TableRouteCipher cipher(key); 

        int op;
        std::string text;
        do {
            std::cout << "\nВыберите операцию:\n";
            std::cout << "1 — Зашифровать текст\n";
            std::cout << "2 — Расшифровать текст\n";
            std::cout << "0 — Выход\n";
            std::cout << "Ваш выбор: ";
            std::cin >> op;

            if (op == 1 || op == 2) {
                std::cout << "Введите текст: ";
                std::cin.ignore(); // Очистка буфера после ввода числа или предыдущей операции
                std::getline(std::cin, text);

                if (op == 1) {
                    std::string encrypted = cipher.encrypt(text);
                    std::cout << "🔒 Зашифрованный текст: " << encrypted << "\n";
                } else if (op == 2) {
                    std::string decrypted = cipher.decrypt(text);
                    std::cout << "🔓 Расшифрованный текст: " << decrypted << "\n";
                }
            } else if (op != 0) {
                std::cout << "⚠️ Неверный выбор. Попробуйте снова.\n";
            }

        } while (op != 0);

        std::cout << "👋 До свидания!\n";

    } catch (const std::exception& e) {
        std::cerr << "❌ Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
