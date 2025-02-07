#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, result = 1;
    cin >> n;
    map<int, int> a;

    n %= 100000;

    for (long long i = 1; i < 3000; ++i) {
        result *= n;
        result %= 10000000;
        a.insert(pair<int, int>(result / 100, i));
    }

    string str;
    char buf;

    cout << "? 6\n";
    cout.flush();
    cin >> buf;
    str += buf;

    cout << "? 5\n";
    cout.flush();
    cin >> buf;
    str += buf;

    cout << "? 4\n";
    cout.flush();
    cin >> buf;
    str += buf;

    cout << "? 3\n";
    cout.flush();
    cin >> buf;
    str += buf;

    cout << "? 2\n";
    cout.flush();
    cin >> buf;
    str += buf;

    cout << "! " << a[stoi(str)] << '\n';
}
