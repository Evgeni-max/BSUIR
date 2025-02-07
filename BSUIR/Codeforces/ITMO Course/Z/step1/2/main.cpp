#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, k;
    cin >> t;

    for(int kk = 0; kk < t; ++kk) {
        string str;
        cin >> str;

        size_t sz = str.size();
        int count = 0;

        for(int n = 1; n < sz; ++n) {
            for(int i = 0; i < sz - n + 1; ++i) {
                bool isEqualPre = true;
                for(int j = 0; j < n; ++j) {
                    if(str[i + j] != str[j]) {
                        isEqualPre = false;
                        break;
                    }
                }

                bool isEqualSuf = true;
                for(int j = 0; j < n; ++j) {
                    if(str[i + j] != str[sz - n + j]) {
                        isEqualSuf = false;
                        break;
                    }
                }

                if((isEqualPre && !isEqualSuf) || (isEqualSuf && !isEqualPre)) {
                    count++;
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}
