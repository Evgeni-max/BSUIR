#include <bits/stdc++.h>
using namespace std;

int main() {
    int jjj;
    cin >> jjj;

    for(int kk = 0; kk < jjj; ++kk) {
        int n;
        cin >> n;

        string buf = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
        int pntr = 1;
        vector<int> z(n);

        string result;

        if (z[0] != 0) {
            cout << '!' << '\n';
        }
        else {
            for(int i = 0; i < n; ++i) {
                bool isNorm = true;

                if(z[i] == 0) {
                    result += string(1, buf[pntr++]);
                }
                else {
                    for(int j = 0; j < z[i]; ++j) {
                        if (result.size() - 1 < i + j) {
                            result += string(1, result[j]);
                        }
                        else {
                            if(result[i + j] != result[j]) {
                                isNorm = false;
                                break;
                            }
                        }
                    }
                }

                if(!isNorm) {
                    cout << '!' << '\n';
                }
            }

            cout << result << '\n';
        }
    }

    return 0;
}