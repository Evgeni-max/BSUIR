#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, k;
    cin >> t;

    for(int kk = 0; kk < t; ++kk) {
        string str;
        cin >> str;

        size_t sz = str.size();

        for(int i = sz - 1; i > -1; --i) {
            bool isPol = true;
            for(int j = 0; j < (i + 1) / 2; ++j) {
                if (str[j] != str[i - j]) {
                    isPol = false;
                    break;
                }
            }

            if(isPol) {
                cout << i + 1 << '\n';
                break;
            }
        }
    }

    return 0;
}
