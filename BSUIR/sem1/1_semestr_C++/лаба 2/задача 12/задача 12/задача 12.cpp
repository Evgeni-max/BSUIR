
#include <iostream>

int main()
{
    double a, b, c, x, y, max, min, z;
    std::cin >> a >> b >> c >> x >> y;

    if (a <= 0 || b <= 0 || c <= 0 || x <= 0 || y <= 0) {
        std::cout << "Incorrect input";
    }
    else {
        if (a > b && a > c) max = a;
        else if (b > c) max = b;
        else max = c;


        if (a < b && a < c) min = a;
        else if (b < c) min = b;
        else min = c;


        b = a + b + c - max - min;
        a = max;
        c = min;


        if (x < y) {
            z = x;
            x = y;
            y = z;
        }

        if (x >= b && y >= c) {
            std::cout << "YES";
        }
        else {
            std::cout << "NO";
        }
    }
}
