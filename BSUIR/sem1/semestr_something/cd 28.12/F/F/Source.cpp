#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    int t;
    std::cin >> t;
    std::pair<const Key, Value>;
    std::unique_ptr<int[]> c = std::make_unique<int[]>(t);

    for (int h = 0; h < t; ++h) {
        int n, count = 0;
        std::cin >> n;

        std::unique_ptr<int[]> a = std::make_unique<int[]>(n);
        std::unique_ptr<int[]> b = std::make_unique<int[]>(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            std::cin >> b[i];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((a[i] < a[j] && b[i] > b[j]) || (a[i] > a[j] && b[i] < b[j]))
                    ++count;
            }
        }

        c[h] = count;
    }

    for (int i = 0; i < t; ++i) {
        std::cout << c[i] << std::endl;
    }
}