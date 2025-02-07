#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    sort(v.begin(), v.end());

    double mnL = 1e18;
    int ind = 0;
    for(int i = 1;;i++){
        if(i + n / 2 - 1 >= n - 1)
            break;
        double d2 = v[i + n / 2 - 1] - v[i];
        double d1 = v[n - 1] - v[0];
        double l = d2 / d1;
        if(l < mnL){
            mnL = l;
            ind = i;
        }
    }
    double d1 = v[n / 2 - 1] - v[0];
    double d2 = v[n - 1] - v[n / 2];
    double l = d2 / d1;
    if(l < mnL){
        mnL = l;
        ind = n / 2;
    }
    swap(d1, d2);
    l = d2 / d1;
    if(l < mnL){
        mnL = l;
        ind = 0;
    }

    cout<<fixed<<setprecision(10)<<mnL<<'\n';

    for(int i = ind; i < ind + n / 2; i++){
        cout<<v[i]<<' ';
    }
}
