#include <iostream>

int main()
{
    long long n, k;
    std::cin >> n >> k;

    if (k == 1) std::cout << "Yes";
    else if (k == 2) {
        if (n >= 2) {
            if (n % 2 == 1) {
                std::cout << "No";
            }
            else std::cout << "Yes";
        }
        else std::cout << "No";
    }
    else if (k == 3 && n == 4) std::cout << "Yes";
    else std::cout << "No";
}


#include <iostream>

int main()
{
    long long n, k;
    std::cin >> n >> k;
    if (k == 3 && n == 4) std::cout << "Yes";
    else if (k == 1)
        std::cout << "Yes";
    else if (n == 2 && k == 2)
        std::cout << "Yes";
    else if (k >= n)
        std::cout << "No";
    else if (n % k == 0)
        std::cout << "Yes";
    else
        std::cout << "No";
}