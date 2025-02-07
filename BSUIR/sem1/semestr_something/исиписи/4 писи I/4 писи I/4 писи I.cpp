#include <vector>
#include <iostream>

int main()
{
    long long n, x;
    std::cin >> n >> x;

    int minlen = n + 1;

    std::vector <int> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int indexs = 0;
    while (indexs < n){
        long long sum = 0; int len = 0;
        for (int j = indexs; j < n; j++) {
            sum += a[j];
            len++;
            if (sum >= x) {
                for (int k = indexs; sum >= x; k++) {
                    sum -= a[k];
                    len--;
                    indexs = k;
                }
                if (len + 1 < minlen) minlen = len + 1;
                break;
            }
        }
        indexs++;
    }
    if (minlen == n + 1) minlen = -1;
    std::cout << minlen;
    return 0;
}
