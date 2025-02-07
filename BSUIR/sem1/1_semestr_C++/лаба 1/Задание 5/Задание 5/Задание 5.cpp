#include <iostream>
#include <iomanip>
int main()
{
    int n = 70;
    double a1, a100;
    std::cin >> a1 >> a100;
    double d = (a100 - a1) / 99;
    double s = (2 * a1 + d * (n - 1)) * 70 / 2;
    std::cout << std::setprecision(10) << d << "\n" << s;
    return 0;
}

