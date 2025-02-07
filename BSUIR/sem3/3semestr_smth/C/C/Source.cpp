#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

void foo(ll n, vector<ll>& del) {
    for (ll k = 1; k * k <= n; ++k) {
        if (n % k == 0) {
            del.push_back(k);

            if (k * k != n)
                del.push_back(n / k);
        }
    }
    sort(del.begin(), del.end());
}

int main() {
    ll n;
    cin >> n;
    long long bufsum = 0, suma = 0;
    vector<ll> a(n), del;

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        suma += a[i];
    }
    
    if (suma == 0) cout << 0;
    else {
    foo(suma, del);

    for (auto d : del) {
        bool podh = 1;
        for (ll i = 0; i < n; ++i) {
            bufsum += a[i];
            if (bufsum == d) {
                bufsum = 0;
            }
            else if (bufsum > d) {
                podh = 0;
                break;
            }
        }
        if (podh) {
            if (bufsum == d || bufsum == 0) {
                cout << (n - 1) - (suma / d - 1);
                return 0;
            }
            else {
                bufsum = 0;
                continue;
            }
        }
        else {
            bufsum = 0;
            continue;
        }
    }
    cout << n - 1;
    }
    
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//using ll = long long;
//
//void foo(ll n, vector<ll>& del) {
//    for (ll k = 1; k <= (ll)round(sqrt(n)); ++k) {
//        if (n % k == 0) {
//            del.push_back(k);
//
//            if (k != (ll)round(sqrt(n)))
//                del.push_back(n / k);
//        }
//    }
//    sort(del.begin(), del.end());
//}
//
//int main() {
//    ll n;
//    cin >> n;
//    ll bufsum = 0, suma = 0;
//    vector<ll> a(n), del;
//
//    for (ll i = 0; i < n; ++i) {
//        cin >> a[i];
//        suma += a[i];
//    }
//    foo(suma, del);
//
//    for (auto d : del) {
//        bufsum = 0;
//        bool podh = 1;
//        for (ll i = 0; i < n; ++i) {
//            bufsum += a[i];
//            if (bufsum == d) {
//                bufsum = 0;
//            }
//            else if (bufsum > d) {
//                podh = 0;
//                break;
//            }
//        }
//        if (podh && bufsum == d) {
//            cout << ((n - 1) - (suma / d - 1));
//            break;
//        }
//    }
//}