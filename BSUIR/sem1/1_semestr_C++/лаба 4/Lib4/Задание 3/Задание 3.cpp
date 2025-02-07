#include <iostream>

int main()
{
    int n, k, m, count = 0;
    std::cin >> n >> k;
    m = n;

    //cin
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }

    int** b = new int* [m];
    for (int i = 0; i < m; i++) {
        b[i] = new int[m];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            b[i][j] = a[i][j];
        }
    }

    int** c = new int* [m];
    for (int i = 0; i < m; i++) {
        c[i] = new int[m];
    }
    while(++count < k) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            b[i][j] = c[i][j];
        }
    }
    }

    //cout
    for (int i = 0; i < m; i++) {
        std::cout << b[i][0];
        for (int j = 1; j < m; j++) {
            std::cout << ' ' << b[i][j];
        }
        std::cout << std::endl;
    }

    // delete
    for (int i = 0; i < n; i++) {
        delete[] a[i];
        a[i] = nullptr;
    }
    delete[] a;
    a = nullptr;

    for (int i = 0; i < n; i++) {
        delete[] b[i];
        b[i] = nullptr;
    }
    delete[] b;
    b = nullptr;

    for (int i = 0; i < n; i++) {
        delete[] c[i];
        c[i] = nullptr;
    }
    delete[] c;
    c = nullptr;

    return 0;
}

