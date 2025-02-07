#include <vector>
#include <iostream>
#include <string>

int main()
{
    std::string A;
    int T, sum = 0, n, x = 0, b;
    std::cin >> T;

    while (x < T) {
        sum = 0;
        std::cin >> n;
        std::vector <int> a(n);

        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            sum += a[i];
        }
        b = sum - n + 1;
        A.append(std::to_string(b));
        A.push_back('\n');
        x++;
    }
    std::cout << A;
}

