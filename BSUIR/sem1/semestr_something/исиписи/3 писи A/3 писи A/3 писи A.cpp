
#include <iostream>
#include <vector>
int main()
{
    int T, length = 1, maxlength = 0, x = 0;
    std::cin >> T;
    while (x < T) {
        int n, length = 1, maxlength = 0;
        std::cin >> n;
        std::vector <int> a(n + 1);
        
        for (int i = 1; i < n + 1; i++) {
            std::cin >> a[i];
        }
        metka;
        max = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i + 1]) {
                length++;
            }
            else {
                if (length != 1 && maxlength < length) maxlength = length;
            }
        }
        if (length != 1 && maxlength < length) maxlength = length;
        std::cout << maxlength << '\n';
        x++;
    }
    return 0;
}







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
