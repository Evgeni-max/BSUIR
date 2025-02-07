
#include <iostream>
#include <vector>
int main()
{
    long long sum = 0, max = 0, maxi = 0, lastmaxi = 0, coin = 0, n;
    std::cin >> n;
    std::vector <long long> a(n + 1);

    for (long long i = 1; i < n + 1; i++) {
        std::cin >> a[i];
    }

    metka:
    lastmaxi = maxi;
    max = 0;
    sum = 0;
    for (long long i = maxi + 1; i < n + 1; i++) {
        if (max <= a[i]) {
            max = a[i];
            maxi = i;
        }
    }
    if (maxi == lastmaxi + 1) goto metka;
    else {
        for (long long i = lastmaxi + 1; i < maxi; i++) {
            sum += a[i];
        }
        coin += max * (maxi - 1 - lastmaxi) - sum;
        if (maxi != n) goto metka;
    }
    std::cout << coin;
    return 0;
}

