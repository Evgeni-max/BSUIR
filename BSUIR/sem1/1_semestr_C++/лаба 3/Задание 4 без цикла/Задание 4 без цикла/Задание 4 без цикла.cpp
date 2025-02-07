
#include <iostream>

int main()
{
    int n, k;
    std::cin >> n;

    if (n <= 0) {
        std::cout << "ERROR";
    }
    else {
        k = n / 2;

        int x = (4 + 2 * (k - 1)) * k / 2;
        std::cout << x;
    }
    return 0;
}
