#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

long long mod(long long a, long long b) {
    if (a < b) std::swap(a, b);

    while (b != 0) {
        a = a % b;
        std::swap(a, b);
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long p, q, strelka1, strelka2;
    cin >> p >> q >> strelka1 >> strelka2;

    long long limit = 12 * 60 * 60;
    set<long long> a;

    if (strelka1 == 1) {
        if (strelka2 == 2) {
            long long base_chis = 3600 * q, base_znam = 59 * q, dobavok = 10 * p, count = 1;
            
            a.insert(dobavok);

            while (dobavok + base_chis * count < base_znam * limit) {
                a.insert(-dobavok + base_chis * count);
                a.insert(dobavok + base_chis * count);
                ++count;
            }

            if (-dobavok + base_chis * count < base_znam * limit)
                 a.insert(-dobavok + base_chis * count);

            cout << a.size() << '\n';

            long long buf_mod;

            for (auto& v : a) {
                buf_mod = mod(v, base_znam);
                cout << v / buf_mod << ' ' << base_znam / buf_mod << '\n';
            }
        }
        else {
            long long base_chis = 3600 * 120 * q, base_znam = 719 * q, dobavok = 120 * p, count = 1;

            a.insert(dobavok);

            long double d = ((long double)dobavok + (long double)base_chis * count) / (long double)base_znam;

            while (d < limit) {
                a.insert(-dobavok + base_chis * count);
                a.insert(dobavok + base_chis * count);
                ++count;
                d = ((long double)dobavok + (long double)base_chis * count) / (long double)base_znam;
            }

            d = (-(long double)dobavok + (long double)base_chis * count) / (long double)base_znam;

            if (d < limit)
                a.insert(-dobavok + base_chis * count);

            cout << a.size() << '\n';

            long long buf_mod;

            for (auto& v : a) {
                buf_mod = mod(v, base_znam);
                cout << v / buf_mod << ' ' << base_znam / buf_mod << '\n';
            }
        }
    }
    else {
        long long base_chis = 360 * 120 * q, base_znam = 11 * q, dobavok = 120 * p, count = 1;

        a.insert(dobavok);

        while (dobavok + base_chis * count < base_znam * limit) {
            a.insert(-dobavok + base_chis * count);
            a.insert(dobavok + base_chis * count);
            ++count;
        }

        if (-dobavok + base_chis * count < base_znam * limit)
            a.insert(-dobavok + base_chis * count);

        cout << a.size() << '\n';

        long long buf_mod;

        for (auto& v : a) {
            buf_mod = mod(v, base_znam);
            cout << v / buf_mod << ' ' << base_znam / buf_mod << '\n';
        }
    }
}