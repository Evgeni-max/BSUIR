
#include <iostream>

int main()
{
    double a, b, c, y;
    int N;
    std::cin >> N >> a >> b >> c;

    switch (N) {
    case 2:
        y = b * c - a * a;
        break;
    case 56:
        y = b * c;
        break;
    case 7:
        y = pow(a, 7) + c;
        break;
    case 3:
        y = a - b * c;
        break;
    default:
        y = pow(a + b, 3);
    }
    std::cout << y;
    return 0;
}

