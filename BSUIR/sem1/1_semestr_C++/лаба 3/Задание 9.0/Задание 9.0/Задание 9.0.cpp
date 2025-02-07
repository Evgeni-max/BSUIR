
#include <iostream>

int main()
{
    long long int n, sum = 0;
    std::cin >> n;

    if (n == 0) std::cout << 0;
    else {
        for (long long int i = 0; i < n + 1; i++) {
            sum += i;
        }

        long long int b = sum - n + 1;
        std::cout << b;
    }
    return 0;
}

