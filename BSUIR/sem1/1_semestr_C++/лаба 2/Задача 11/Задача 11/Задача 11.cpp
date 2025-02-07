#include <math.h>
#include <iostream>

int main()
{
    double p, q, r;
    std::cin >> r >> p >> q;
     
    if (p * sin(q / 180 * atan(1) * 4) / 2 < r) std::cout << "NO";
    else std::cout << "YES";

    return 0;
}

