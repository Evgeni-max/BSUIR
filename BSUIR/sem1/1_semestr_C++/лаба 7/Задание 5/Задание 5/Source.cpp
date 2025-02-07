#include <iostream>

int main()
{
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;

        int result = n / 10 + (n % 10 == 9);

        std::cout << result << std::endl;
    }
}