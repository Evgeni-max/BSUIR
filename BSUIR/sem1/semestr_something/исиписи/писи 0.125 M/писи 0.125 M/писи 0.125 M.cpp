#include <math.h>
#include <iostream>
#include <iomanip>

int main()
{
    long double a, b, c, x, value;
    std::cin >> a >> b >> c;
    
    x = sqrt(b / c);
    value = a / 2 / sqrt(b * c);

    std::cout << std::fixed << std::setprecision(9) << x << ' ' << value;

    return 0;
}

