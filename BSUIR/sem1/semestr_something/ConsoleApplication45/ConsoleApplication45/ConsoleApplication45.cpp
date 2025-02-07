#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    int t;
    std::cin >> t;

    for (int h = 0; h < t; ++h) {
        int size_array = 0;
        std::cin >> size_array;

        unsigned long long buf = 0;
        long double P1 = 1, P2 = 1;

        for (int i = 0; i < size_array; ++i) {
            std::cin >> buf;
            if (buf != 1)
                P1 *= log(buf);
        }

        for (int i = 0; i < size_array; ++i) {
            std::cin >> buf;
            if (buf != 1)
               P2 *= log(buf);
        }

        if (P1 == P2 || fabs(P1 - P2) < 0.0000001)
            std::cout << '=' << std::endl;
        else if (P1 > P2)
            std::cout << '>' << std::endl;
        else
            std::cout << '<' << std::endl;
    }
}