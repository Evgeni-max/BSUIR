
#include <math.h>
#include <iostream>

int main()
{
    double y = atan(1);

    for (double x = 0; x <= y * 2; x += y / 10) {
        std::cout << sin(x) - cos(x) << ' ';
    }

    return 0;
}
