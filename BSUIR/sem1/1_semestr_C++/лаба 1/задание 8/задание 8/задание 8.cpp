

#include <iostream>

int main()
{
    int h1, min1, h2, min2, h3, min3;
    std::cin >> h1 >> min1 >> h2 >> min2;

    h3 = h2 - h1;
    min3 = min2 - min1;

    if (h1 > h2) {
        h3 += 24;
    }
    if (min1 > min2) {
        min3 += 60;
        h3 -= 1;
    }
    if (h1 == h2 && min1 > min2) {
        h3 = 23;
    }
    std::cout << h3 << ":" << min3;
    return 0;
}


