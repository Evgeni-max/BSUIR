#include <bits/stdc++.h>
using namespace std;

int sum(int n) {return n * (n + 1) / 2;}

bool isStringOfOneChar(string& str) {
    for(int i = 1; i < str.size(); ++i) {
        if(str[i] != str[0]) {
            return false;
        }
    }
    return true;
}

int main() {
    int jjj;
    cin >> jjj;

    for(int kk = 0; kk < jjj; ++kk) {
        string t, p;
        cin >> t >> p;

        int szT = t.size(), szP = p.size();
        vector<int> in;

        for(int i = 0; i <= szT - szP; ++i) {
            bool isEqu = true;
            for(int j = 0; j < szP; ++j) {
                if (t[i + j] != p[j]) {
                    isEqu = false;
                    break;
                }
            }

            if(isEqu) {
                in.push_back(i);
            }
        }

        int count = 0;
        if(in.size() == 0) {
            count = sum(szT);
        }
        else if(szP == 1) {
            count += sum(in[0]);
            for(int i = 1; i < in.size(); ++i) {
                count += sum(in[i] - in[i - 1] - 1);
            }

            count += sum(szT - in[in.size() - 1] - 1);
        }
        else {
            count += sum(in[0] + szP - 1);
            for(int i = 1; i < in.size(); ++i) {
                count += sum(in[i] - in[i - 1]);
            }

            count += sum(szT - in[in.size() - 1] - szP + 1);
        }

        cout << count << '\n';
    }

    return 0;
}