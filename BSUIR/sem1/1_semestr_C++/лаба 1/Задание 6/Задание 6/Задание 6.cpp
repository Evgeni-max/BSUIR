
#include <iostream>
#include <cmath>

int main()
{
    double A, K, C, D, h, x, p;
    std::cin >> K >> C >> D >> h >> x >> p;
    A = x - p;
    double Y = 0.78 * log(h) + powl(A, 3) / K / C / D;
    std::cout << Y;
    return 0;
}

