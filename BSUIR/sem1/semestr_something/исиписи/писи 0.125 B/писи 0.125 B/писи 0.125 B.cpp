
#include <iostream>

int main()
{
    int p, q, a, x, y, z;
    std::cin >> p >> q >> a;
    
    x = a / (p * q + q + 1);
    y = q * x;
    z = p * y;

    std::cout << z << ' ' << y << ' ' << x;

    return 0;
}

