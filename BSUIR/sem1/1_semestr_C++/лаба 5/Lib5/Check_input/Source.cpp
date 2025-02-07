#include <iostream>

const int MAX_LENGTH = 100; // Максимальная длина вводимой строки

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

int convertToInt(const char* input) {
    int result = 0;
    int i = 0;

    while (input[i] != '\0') {
        result = result * 10 + (input[i] - '0');
        i++;
    }

    return result;
}

int getInputNumber() {
    std::setlocale(0, "Russian");
    char input[MAX_LENGTH];
    int index = 0;

    std::cout << "Введите число: ";

    char c;
    while (std::cin.get(c)) {
        if (c == '\n') {
            break;  // Прекращаем чтение при вводе символа новой строки
        }

        if (isDigit(c)) {
            input[index] = c;
            index++;

            if (index >= MAX_LENGTH - 1) {
                break;  // Прекращаем чтение, если достигнута максимальная длина массива
            }
        }
        else {
            std::cout << "Ошибка ввода!" << std::endl;
            return -1; // Возвращаем -1 в случае ошибки ввода
        }
    }

    input[index] = '\0';  // Добавляем нулевой символ в конце массива

    return convertToInt(input);
}