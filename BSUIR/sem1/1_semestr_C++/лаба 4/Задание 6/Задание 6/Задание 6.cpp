#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::getline(std::cin, str);
    int p = str.size();               // int p = std::size(str);

    char num[] = "0123456789";
    int count = 0, j;

    std::cin >> j;

    for (int i = 0; i < 10; i++) {
        count += str.find(num[i]) != -1;
    }

    std::cout << count << '\n';

    std::size_t found = str.find_last_of(str[j - 1]);
    while (found != std::string::npos)
    {
        std::cout << p - found - 1 << ' ';
        found = str.find_last_of(str[j - 1], found - 1);
    }

    return 0;
}
