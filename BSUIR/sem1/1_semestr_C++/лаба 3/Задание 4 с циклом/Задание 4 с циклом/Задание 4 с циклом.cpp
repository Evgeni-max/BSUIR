
#include <iostream>

int main()
{
    int n, sum = 0;
    std::cin >> n;

    if (n <= 0) {
        std::cout << "ERROR";
    }
    else {
        for (int i = 2; i < n + 1; i += 2) {
            sum += i;
        }
    }

    std::cout << sum;
}
