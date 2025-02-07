#include <iostream>
#include <iomanip>
#include <string>


int main()
{
    int t;
    std::cin >> t;

    for (int h = 0; h < t; ++h) {
        int n;
        unsigned long long sum = 0, square = 0;

        std::cin >> n;

        std::unique_ptr<int[]> a = std::make_unique<int[]>(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            sum += a[i];
        }

        while (sum > ++square * square);

        if (sum == square * square)
            std::cout << "YES";
        else
            std::cout << "NO";

        std::cout << std::endl;
    }
}