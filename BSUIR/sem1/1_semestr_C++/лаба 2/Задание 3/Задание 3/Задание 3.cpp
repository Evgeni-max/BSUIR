
#include <iostream>

int main()
{
    int x, y;
    double a, b, c, k;
    std::cin >> x >> y >> a >> b >> c >> k;

    if (x > y) y = 0;
    else if (y > x) x = 0;
    else x = 0, y = 0;

    if (a > b && a > c) a -= k;
    else if (b > c) b -= k;
    else c -= k;

    std::cout << x << ' ' << y << '\n' << a << ' ' << b << ' ' << c;

    return 0;
}
