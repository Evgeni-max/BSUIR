#include <iostream>
#include <climits>
#include <algorithm>

int main()
{
    int kline, gcolumn, counter = 0, x;
    std::cin >> kline >> gcolumn;


    //создание массив
    int** a = new int* [kline + 1];
    for (int i = 0; i < kline + 1; i++) {
        a[i] = new int[gcolumn + 1];
    }


    //считывание
    for (int j = 0; j < gcolumn + 1; j++) {
        a[0][j] = INT_MIN;
    }

    for (int i = 0; i < kline + 1; i++) {
        a[i][0] = INT_MIN;
    }

    for (int i = 1; i < kline + 1; i++) {
        for (int j = 1; j < gcolumn + 1; j++) {
            std::cin >> a[i][j];
        }
    }

    //работа
    for (int i = 1; i < kline + 1; i++) {
        for (int j = 1; j < gcolumn + 1; j++) {
            x = std::max(a[i - 1][j], a[i][j - 1]);
            if (a[i][j] < x) a[i][j] = x;
        }
    }

    //вывод 
    for (int i = 1; i < kline + 1; i++) {
        for (int j = 1; j < gcolumn + 1; j++) {
            std::cout << a[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    //удаление
    for (int i = 0; i < kline + 1; i++) {
        delete[] a[i];
        a[i] = nullptr;
    }
    delete[] a;
    a = nullptr;

    return 0;
}