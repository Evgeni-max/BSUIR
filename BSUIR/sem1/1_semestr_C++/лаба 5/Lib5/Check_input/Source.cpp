#include <iostream>

const int MAX_LENGTH = 100; // ������������ ����� �������� ������

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

    std::cout << "������� �����: ";

    char c;
    while (std::cin.get(c)) {
        if (c == '\n') {
            break;  // ���������� ������ ��� ����� ������� ����� ������
        }

        if (isDigit(c)) {
            input[index] = c;
            index++;

            if (index >= MAX_LENGTH - 1) {
                break;  // ���������� ������, ���� ���������� ������������ ����� �������
            }
        }
        else {
            std::cout << "������ �����!" << std::endl;
            return -1; // ���������� -1 � ������ ������ �����
        }
    }

    input[index] = '\0';  // ��������� ������� ������ � ����� �������

    return convertToInt(input);
}