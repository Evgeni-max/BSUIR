// Вариант 2


#include <iostream>

int main()
{
    int chek = 0, n, m, a[200][200];

    std::cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i][j] < 0) chek++;
        }
    }

    std::cout << chek;
}

