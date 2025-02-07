#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>

int main()
{
    int t;
    std::cin >> t;

    for (int h = 0; h < t; ++h) {
        long long n, x, y;
        
        std::cin >> n >> x >> y;
        std::vector<long long> a(n);
        long long total = 0, ar = x * y; 

        for (long long i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        long long g = 0;
        for (long long i = 0; i < n; ++i) {
             for (long long j = i + 1; j < n; ++j) {
                 g = (a[i] * a[i] - a[j] * a[j]) % ar == 0;

                 if (a[i] * a[i] - a[j] * a[j] == 0) {
                     if ((a[i] + a[j]) % x == 0) {
                         ++total;
                     }
                 }
                 else {
                     if (g) {
                         ++total;
                     }
                 }
                     
             }
        }

        std::cout << total << std::endl;
    }
}