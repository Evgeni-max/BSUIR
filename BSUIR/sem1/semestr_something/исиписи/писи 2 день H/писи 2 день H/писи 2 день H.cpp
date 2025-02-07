
#include <iostream>
#include <vector>

int main()
{
    int n, m, p, q, degree_numer = 0, degree_deter = 0;
    std::cin >> n >> m;


    std::vector <int> a(n + 1);
    std::vector <int> b(m + 1);


    for (int i = 0; i < (n + 1); i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < (m + 1); i++) {
        std::cin >> b[i];
    }


    for (int i = n; i >= 0; i--) {
        if (a[i] != 0) {
            p = a[i];
            degree_numer = i;
            break;
        }
    }
    for (int i = m; i >= 0; i--) {
        if (b[i] != 0) {
            q = b[i];
            degree_deter = i;
            break;
        }
    }

    if (degree_deter == 0) std::cout << 0 << ' ' << 0;
    else if (degree_numer > degree_deter) {
        std::cout << 1 << ' ' << 0;
    }
    else if (degree_numer < degree_deter) {
        std::cout << 0 << ' ' << 1;
    }
    else {
        int y, x;
        x = p;
        y = q;
        while (x != y) {
            if (x > y) {
                x = x - y;
            }
            else {
                y = y - x;
            }
        }
        p = p / x;
        q = q / x;
        std::cout << p << ' ' << q;
    }
    return 0;
}

