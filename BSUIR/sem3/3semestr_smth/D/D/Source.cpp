#include <iostream>
#include <vector>
#define  mod 998244353

using namespace std;

int main() {
	unsigned long long n;
	cin >> n;
	vector<unsigned long long> a(n), b(n), pr_b(n),pr_s(n + 1);
	if (n == 1) {
		cin >> a[0];
		unsigned long long q, l, r;
		cin >> q;
		for (long long i = 0; i < q; ++i) {
			cin >> l >> r;
			cout << a[0] << '\n';
		}
	}
	else {
		b[n - 1] = 1;

		for (long long i = 0; i < n; ++i) {
			cin >> a[i];
		}

		for (long long i = 0; i < n - 1; ++i) {
			cin >> b[i];
		}

		unsigned long long prz = 1;
		pr_b[n - 1] = prz;

		for (long long i = n - 2; i >= 0; --i) {
			prz = prz * b[i] % mod;
			pr_b[i] = prz;
		}

		unsigned long long sum = 0;
		pr_s[n] = 0;

		for (long long i = n - 1; i >= 0; --i) {
			sum = (sum + pr_b[i] * a[i] % mod) % mod;
			pr_s[i] = sum;
		}

		/*for (int i = 0; i < n; ++i) {
			cout << a[i] << '\t' << b[i] << '\t' << pr_b[i] << '\t' << pr_s[i] << '\n';
		}
		cout << '\n';*/

		unsigned long long q, l, r;
		cin >> q;
		for (long long i = 0; i < q; ++i) {
			cin >> l >> r;
			cout << (pr_s[l - 1] - pr_s[r]) / pr_b[r - 1] << '\n';
		}
	}
}