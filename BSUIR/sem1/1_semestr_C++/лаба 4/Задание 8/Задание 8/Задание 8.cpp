
#include <iostream>

int main()
{
    int n, m;
    std::cin >> n;

    //cin
    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }

    std::cin >> m;
    int** b = new int* [m];
    for (int i = 0; i < m; i++) {
        b[i] = new int[m];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> b[i][j];
        }
    }

    int** c = new int* [m];
    for (int i = 0; i < m; i++) {
        c[i] = new int[m];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = 0;
        }
    }

    //work
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    //cout
    for (int i = 0; i < m; i++) {
        std::cout << c[i][0];
        for (int j = 1; j < m; j++) {
            std::cout << ' ' << c[i][j];
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
