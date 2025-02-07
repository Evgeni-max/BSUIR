
#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    if (a % b && b % a) std::cout << "NO";
    else std::cout << "YES";
}
