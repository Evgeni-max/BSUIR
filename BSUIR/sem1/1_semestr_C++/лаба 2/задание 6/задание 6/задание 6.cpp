#include <iomanip>
#include <iostream>

int main()
{ 
    std::cout << std::setprecision(20);

    double a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if (c == 0) std::cout << "ERROR";
    else if (c >= d && a < d) {
        std::cout << a + b / c;
    }
    else if (c < d && a >= d) {
        std::cout << a - b / c;
    }
    else std::cout << 0;
}
