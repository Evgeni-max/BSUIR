
#include <iostream>

int main()
{
    int n, a, x = 1, sum;

    std::cin >> n;
    std::cin >> sum;

    for (int i = 0; i < n - 1; i++) {
        std::cin >> a;
        x *= -2;
        sum += x * a;
    }

    std::cout << sum;
}

