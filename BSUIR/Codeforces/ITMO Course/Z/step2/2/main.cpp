#include <bits/stdc++.h>
using namespace std;

int main() {
    int jjj;
    cin >> jjj;

    for(int kk = 0; kk < jjj; ++kk) {
        int k, j;
        cin >> k >> j;

        int degree = 1;

        if (j == 0) {
            cout << 0 << '\n';
            continue;
        }

        while(j % 2 == 0) {
            j /= 2;
            degree *= 2;
        }

        cout << degree - 1 << '\n';
    }

    return 0;
}
