/*#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> del(int k) {
    vector<pair<int, int>> dels;
    for(int i = 1; i <= sqrt(k); ++i) {
        if(k % i == 0) dels.push_back(pair<int, int>(i, k / i));
    }
    return dels;
}

int main() {
    int t, k;
    cin >> t;

    for(int kk = 0; kk < t; ++kk) {
        int n, m, L;
        cin >> n, m, L;

        vector<char> stones(L + 1);
        vector<vector<pair<int, int>>> dp(L + 1);
        vector<vector<int>> st(L + 1);

        int l, r;
        for(int h = 0; h < n; ++h) {
            cin >> l >> r;

            for(int i = l; i <= r; ++i) {
                stones[i] = 1;
            }
        }

        int x, v;
        for(int h = 0; h < m; ++h) {
            cin >> x >> v;

            st[x].push_back(v);
        }

        dp[1] = vector<pair<int, int>>({(0, 1)});
        for(int i = 2; i < L + 1; ++i) {
            for(auto d : dp[i]) {

                for (auto g)
                if(stones[i + d.second] != 1 && i + d.second < L + 1)
                dp[i + d.second].push_back(d);
            }
        }
        cout << -1 << '\n';

    }

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

bool d(unsigned long long x, unsigned long long y) {
    if (y == 0) return false;
    else return x % y == 0;
}

void  counting(unsigned long long x, unsigned long long m) {
    //unsigned long long count = 0;
    for (unsigned long long y = 1; y <= m; ++y) {
        if (y != x && (d(x, x^y))) cout << y << ' ';
    }
    cout << '\n';

    for (unsigned long long y = 1; y <= m; ++y) {
        if (y != x && ( d(y, x^y))) cout << y << ' ';
    }
    cout << '\n';
    //return count;
}

int main() {
    int t;
    unsigned long long x, m;
    cin >> t;

    for(unsigned long long kk = 0; kk < t; ++kk) {
        cin >> x >> m;

        counting(x, m);
        //cout << counting(x, m) << '\n';
    }
    return 0;
}