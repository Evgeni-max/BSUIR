// писи 2 B.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <vector>

int main()
{
    int n = 0, count = 0, stop = 0;
    std::cin >> n;
    std::vector <int>a(n + 2);
    a[0] = 0;
    for (int i = 1; i <= n + 1; i++) {
        std::cin >> a[i];
    }
    int i = 1;
    while (i <= n + 1 && i >= 1 && stop < n) {
        if (a[n + 1] == 0) {
            for (int m = 1; m <= n + 1; m++) {
                if (a[m] != m) {
                    a[m] = 0;
                    a[n + 1] = m;
                    count++;
                    break;
                }
            }
            i = 0;
        }
        else {
            if (a[i] == 0) {
                for (int j = 1; j <= n + 1; j++) {
                    if (a[j] == i) {
                        a[i] = i;
                        a[j] = 0;
                        count++;
                        break;
                    }
                }
                i = 0;
            }
        }
        stop = 0;
        for (int u = 1; u <= n; u++) {
            if (a[u] == u && a[n + 1] == 0) {
                stop++;
            }
        }
        i++;
    }
    std::cout << count;
}

