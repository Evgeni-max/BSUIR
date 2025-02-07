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

int main() {
    string str;
    cin >> str;

    vector<int> z = Zfunc(str);

    for(int v : z) cout << v << ' ';
    cout << '\n';

    return 0;
}
