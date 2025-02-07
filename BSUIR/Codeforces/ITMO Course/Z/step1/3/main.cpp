#include <bits/stdc++.h>
using namespace std;

int main() {
    int jjj;
    cin >> jjj;

    for(int kk = 0; kk < jjj; ++kk) {
        string t, p;
        cin >> t >> p;

        int szT = t.size(), szP = p.size();
        vector<int> count;

        for(int i = 0; i <= szT - szP; ++i) {
            bool isEqu = true;
            for(int j = 0; j < szP; ++j) {
                if (p[j] != '?' && t[i + j] != p[j]) {
                    isEqu = false;
                    break;
                }
            }

            if(isEqu) {
                count.push_back(i);
            }
        }

        cout << count.size() << '\n';
        for(int i : count) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}
