
#include <iostream>

void zamena(int number, char* result) {
    int i = 0;
    // Обрабатываем каждую цифру числа, начиная с конца
    while (number > 0) {
        int s = number % 10;
        result[i++] = 48 + s;
        number /= 10;
    }

    // Переворачиваем значения
    int left = 0, right = i - 1;
    while (left < right) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
        left++; right--;
    }

    result[i] = '\0';
}


int main() {
    const int arraySize = 3;
    char str[80];
    int q = 0;

    for (int i = 0; i < 100; i++) {
        str[i] = getchar();
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        q++;
    }

    char t[200];
    int e = 0;
    for (int i = 0; i < 200; i++) { t[i] = '\0'; }
    for (int i = 0, j = 0; i < q; i++, j++) {
        e = 0;
        if (str[i] == str[i + 1]) {
            while (str[i] == str[i + 1]) {
                i++;
                e++;
            }

            t[j] = '2';
            t[++j] = '5';
            t[++j] = '5';

            char temp[4];
            int h = 0;

            zamena(int(str[i]), temp);
            while (temp[h] != '\0') {
                t[++j] = temp[h++];

            }

            h = 0;

            zamena(e + 1, temp);
            while (temp[h] != '\0') {
                t[++j] = temp[h++];

            }

        }
        else {
            t[j] = str[i];
        }
    }
    std::cout << t;
    return 0;
}