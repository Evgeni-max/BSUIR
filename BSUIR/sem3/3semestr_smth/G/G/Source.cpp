#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ll TT = 0;
    cin >> TT;
    for (ll yyy = 0; yyy < TT; ++yyy) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), b(n);
        for (ll& el : a) {
            cin >> el;
        }
        for (ll& el : b) {
            cin >> el;
        }
        for (ll& el : a) {
            el %= m;
        }
        for (ll& el : b) {
            el %= m;
        }
        sort(a.begin(), a.end());

        auto foo = [m](ll a, ll b) {
            ll r = (a - b) % m;
            if (r < 0) r += m;
            return r;
            };

        ll d = 0;
        for (ll i = 0; i < n; ++i) {
            ll cur = a[i];
            ll min = foo(cur, b[0]);
            ll m_j = 0;
            for (ll j = 0; j < b.size(); ++j) {
                if (foo(cur, b[j]) < min) {
                    min = foo(cur, b[j]);
                    m_j = j;
                }
            }
            d += min;
            b.erase(b.begin() + m_j);
        }
        cout << d << endl;
    }
}
