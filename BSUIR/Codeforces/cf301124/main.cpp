#include <bits/stdc++.h>
using namespace std;

vector<int> Zfunc(string& str) {
    vector<int> z(str.size(), 0);

    int l = 0, r = 0;
    for(int i = 1; i < str.size(); ++i) {
        if (r >= i) z[i] = min(r - i + 1, z[i - l]);

        while(i + z[i] < str.size() && str[i + z[i]] == str[z[i]]) ++z[i];

        if(r < i + z[i]) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

int gcd(int a, int b) {
    return b ? gcd (b, a % b) : a;
}
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    vector<int> dn {-1, 1, 0, 0};
    vector<int> dm {0, 0, -1, 1};
    vector<char> dd {'U', 'D', 'L', 'R'};

    int t;
    cin >> t;

    for(int kkk = 0; kkk < t; ++kkk) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> z(n, vector<char>(m));

        int rst = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> z[i][j];
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(z[i][j] != '?') continue;
                else {
                    bool check = false;
                    int nn, nm;
                    for(int h = 0; h < 4; ++h) {
                        nn = dn[h] + i;
                        nm = dm[h] + j;
                        if ((nn < 0 || nn >= n || nm < 0 || nm >= m) || z[nn][nm] == '?') continue;

                        if (z[nn][nm] == dd[h]) {
                            check = true;
                            break;
                        }
                    }

                    if(!check) ++rst;
                }
            }
        }
        cout << rst << '\n';
    }

    return 0;
}