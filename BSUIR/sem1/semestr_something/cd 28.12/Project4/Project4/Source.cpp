//#include <iostream>
//#include <iomanip>
//#include <algorithm>
//#include <vector>
//#include <utility>
//
//int main()
//{
//    int t;
//    std::cin >> t;
//
//    for (int h = 0; h < t; ++h) {
//        long long n, q;
//        std::cin >> n >> q;
//        std::vector<int> a(n);
//        std::vector<long long> x(n + 1);
//
//        for (int i = 0; i < n; ++i) {
//            std::cin >> a[i];
//
//            if (a[i] == 1) {
//                a[i] -= 2;
//            }
//            else
//                a[i] -= 1;
//        }
//
//        x[0] = 0; 
//
//
//        for (int i = 0; i < n; ++i) {
//            x[i + 1] = x[i] + a[i];
//        }
//
//        for (int z = 0; z < q; ++z)
//        {
//                int l, r;
//                std::cin >> l >> r;
//
//                if (l == r) {
//                    std::cout << "NO" << std::endl;
//                    continue;
//                }
//
//                long long count1 = 0, count2 = 0;
//
//                count1 += x[r] - x[l - 1];
//
//                if (count1 > -1) {
//                    std::cout << "YES" << std::endl;
//                }
//                else
//                    std::cout << "NO" << std::endl;
//        }
//    }
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> findMinTimeToBeEaten(vector<int>& sizes) {
//    int n = sizes.size();
//    vector<int> result(n, -1);
//
//    for (int i = 0; i < n; i++) {
//        if (i > 0 && sizes[i] > sizes[i - 1]) {
//            result[i] = 1;
//        }
//        if (i < n - 1 && sizes[i] > sizes[i + 1]) {
//            result[i] = (result[i] == -1) ? 1 : min(result[i], 1);
//        }
//    }
//
//    int maxTime = -1;
//    for (int i = 0; i < n; i++) {
//        if (result[i] == -1) {
//            maxTime = max(maxTime, sizes[i]);
//        }
//    }
//
//    for (int i = 0; i < n; i++) {
//        if (result[i] == -1) {
//            result[i] = maxTime - sizes[i] + 1;
//        }
//    }
//
//    return result;
//}
//
//int main() {
//    int t;
//    cin >> t;
//
//    while (t--) {
//        int n;
//        cin >> n;
//
//        vector<int> sizes(n);
//        for (int i = 0; i < n; i++) {
//            cin >> sizes[i];
//        }
//
//        vector<int> result = findMinTimeToBeEaten(sizes);
//
//        for (int i = 0; i < n; i++) {
//            cout << result[i] << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define modul 1000000007

unsigned long long bin_pow(unsigned long long base, unsigned long long p, unsigned long long MOD) {
	if (p == 0) {
		return 1;    //Выход из рекурсии.
	}

	if (p == 1) {
		return base;    //Выход из рекурсии.
	}

	if (p % 2 == 0) {
		unsigned long long t = bin_pow(base, p / 2, MOD);
		return t * t % MOD;
	}
	else {
		return bin_pow(base, p - 1, MOD) * base % MOD;
	}
}

unsigned long long t(int n) {

	if (n == 1) {
		return 1;
	}
	else {
		int buf = sqrt(2 * n + 1);
		double b = sqrt(2 * n + 1);

		if (b - buf > 0.5) {
			++buf;
		}

		int k = n - buf + 1;

		return ((2 * (t(k) % modul) % modul) + bin_pow(2, n - k, modul) - 1) % modul;
	}
}

int main()
{
	unsigned long long n;
	std::vector<unsigned long long> a;
	std::cin >> n;

	std::cout << t(n) << std::endl;
	
}