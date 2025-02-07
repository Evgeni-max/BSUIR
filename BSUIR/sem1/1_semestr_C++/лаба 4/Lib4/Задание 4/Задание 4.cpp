#include <iostream>

int main()
{
    int kline, gcolumn, counter = 0;
    bool x, y;
    std::cin >> kline >> gcolumn;
    

    //создание массива 
    int** a = new int* [kline + 2];
    for (int i = 0; i < kline + 2; i++) {
        a[i] = new int[gcolumn + 2];
    }

    //считывание
    for (int j = 0; j < gcolumn + 2; j++) {
        a[0][j] = INT_MAX;
        a[kline + 1][j] = INT_MAX;
    }

    for (int i = 0; i < kline + 2; i++) {
        a[i][gcolumn + 1] = INT_MAX;
        a[i][0] = INT_MAX;
    }

    for (int i = 1; i < kline + 1; i++) {
        for (int j = 1; j < gcolumn + 1; j++) {
            std::cin >> a[i][j];
        }
    }

    //работа
    for (int i = 1; i < kline + 1; i++) {
        for (int j = 1; j < gcolumn + 1; j++) {
            x = a[i][j] < a[i + 1][j + 1] && a[i][j] < a[i + 1][j] && a[i][j] < a[i + 1][j - 1] && a[i][j] < a[i][j + 1];
            y = a[i][j] < a[i][j - 1] && a[i][j] < a[i - 1][j - 1] && a[i][j] < a[i - 1][j] && a[i][j] < a[i - 1][j + 1];
            if (x && y) {
                counter++;
            }
        }
    }

    std::cout << counter;

    //удаление
    for (int i = 0; i < kline + 2; i++) {
        delete[] a[i];
        a[i] = nullptr;
    }
    delete[] a;
    a = nullptr;

    return 0;
}