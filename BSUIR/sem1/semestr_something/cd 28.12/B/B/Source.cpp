//#include <iostream>
//#include <iomanip>
//#include <algorithm>
//#include <vector>
//#include <utility>
//
//bool compare(const std::pair<int,int>& left, const std::pair<int, int>& right)
//{
//    return left.first < right.first;
//}
//
//int main()
//{
//    int t;
//    std::cin >> t;
//
//    for (int h = 0; h < t; ++h) {
//        long long n, k;
//        std::cin >> n >> k;
//        std::vector<int> a(n);
//        std::vector<int> x(n);
//        std::vector<std::pair<int, int>> p(n);
//
//        for (int i = 0; i < n; ++i) {
//            std::cin >> a[i];
//        }
//
//        for (int i = 0; i < n; ++i) {
//            std::cin >> x[i];
//            x[i] = abs(x[i]);
//        }
//
//        for (int i = 0; i < n; ++i) {
//            p[i].first = x[i];
//            p[i].second = a[i];
//        }
//
//
//        std::sort(p.begin(), p.end());
//
//        long long last_i = 0, count_of_k = 0, a_count = 0;
//        bool victory = true;
//
//        for (int i = 0; i < n; ++i) {
//            count_of_k += k * (p[i].first - last_i);
//            last_i = p[i].first;
//            a_count += p[i].second;
//
//            if (count_of_k < a_count) {
//                victory = false;
//                break;
//            }
//        }
//
//        if (count_of_k < a_count) {
//            victory = false;
//        }
//
//        if (victory) {
//            std::cout << "YES" << std::endl;
//        }
//        else
//            std::cout << "NO" << std::endl;
//    }
//}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long m;

long long bin_pow(long long base, long long p, long long MOD) {
	if (p == 1) {
		return base;    //Выход из рекурсии.
	}

	long long t = bin_pow(base, p / 2, MOD);
    long long tt = t * t % MOD;

	if (p % 2 == 0) {
		return tt;
	}
	else {
		return tt * base % MOD;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    long long n;
    cin >> n >> m;
	long long a, p;

	for (long long i = 0; i < n; ++i) {
		cin >> a >> p;

		cout << bin_pow(a % m, p, m) << '\n';
	}  
}