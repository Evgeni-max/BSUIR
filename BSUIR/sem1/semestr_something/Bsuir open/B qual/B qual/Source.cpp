#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
long long m = 10000009;

long long bin_pow(long long base, long long p, long long MOD) {
    if (p == 1) {
        return base;    //Выход из рекурсии.
    }

    long long t = bin_pow(base, p / 2, MOD);
    long long tt = t * t % MOD;

    if (p % 2 == 0) {
        return tt;
    }
    else {
        return tt * base % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, result = 1;
    cin >> n;

    vector<pair<long long, long long>> a(n);

    for (long long i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].first %= m;
        ++a[i].first;
        a[i].first %= m;
    }
    for (long long i = 0; i < n; ++i) {
        cin >> a[i].second;
        a[i].second %= m;
    }

    for (long long i = 0; i < n; ++i) {
        result = (result * bin_pow(a[i].first, a[i].second, m)) % m;
    }
    
    cout << result - 1;
}
