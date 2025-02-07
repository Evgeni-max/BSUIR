#include <vector>
#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    long long maxlength = 0, length = n, sum = 0, nsum, nlength;
    std::vector <long long> a(n + 1);

    a[0] = 0;

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    
    if (sum % 3 == 0) maxlength = length;
    else {
        for (int i = 0; i < n + 1; i++) {
            sum -= a[i];
            length--;
            if (maxlength >= length) break;
            nsum = sum;
            nlength = length;
            for (int j = n; j > i; j--) {
                if (nsum % 3 == 0) {
                    if (maxlength < nlength) maxlength = nlength;
                    break;
                }
                nsum -= a[j];
                nlength--;
            }
        }
    }
    std::cout << maxlength;
    return 0;
}

