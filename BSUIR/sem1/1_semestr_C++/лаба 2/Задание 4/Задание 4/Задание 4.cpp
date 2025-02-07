
#include <iostream>

int main()
{
    double x, y, max;
    std::cin >> x >> y;
    max = x > y ? x : y;
    std::cout << max;
    max = max ? x : max;

    return 0;
}
