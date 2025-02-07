#include <bits/stdc++.h>
using namespace std;

int main() {
    int jjj = 1;
    //cin >> jjj;

    for(int kk = 0; kk < jjj; ++kk) {
        string t, p;
        cin >> t;

        int szT = t.size();
        vector<int> Zfunc(szT);

        Zfunc[0] = 0;
        for(int i = 1; i <= szT; ++i) {
            while(i + Zfunc[i] < szT && t[i + Zfunc[i]] == t[Zfunc[i]]) ++Zfunc[i];
        }

        for(int i : Zfunc) {
            cout << i << ' ';
        }
    }

    return 0;
}