#include <iostream>

int main()
{
    unsigned long long n;
    std::cin >> n;

    if (n == LLONG_MAX) {
        std::cout << "42535295865117307919086767873688862722";
    }
    else {
        std::cout << n * (n + 1) / 2 - n + 1;
    }

    return 0;
}