#include <iostream>

int main()
{
    unsigned long long n;
    std::cin >> n;
    unsigned long long a = 1, b = 1, c = 1;

    while (a < n) {
        c++;
        b += 2;
        a += b;
    }

    b = (c - 1) * (c - 1);
    a = n - c;
    if (a > b) {
        std::cout << c - 1 << ' ' << c - (n - b - c) - 1;
    }
    else {
        std::cout << n - b - 1 << ' ' << c - 1;
    }
}
