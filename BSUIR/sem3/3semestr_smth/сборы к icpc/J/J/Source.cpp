#include <iostream>
#include <vector>
#define ull unsigned long long
#define ll long long

using namespace std;
ull a, b, p, q;	

ull G(int m) {
	return b / m - (a - 1) / m;
}

int F(int i, int j, vector<ull>& ppow, vector<ull>& qpow) {
	return G(ppow[i] * qpow[j]) - G(ppow[i + 1] * qpow[j]) - G(ppow[i] * qpow[j + 1]) + G(ppow[i + 1] * qpow[j + 1]);
}

int fdExp(int p, int b) {
	ull x = 1, exp = 0;
	while (x <= b) {
		x *= p;
		exp++; 
	} 
	return exp;
}

int main() {
	cin >> a >> b >> p >> q;
	int logbp = fdExp(p, b);
	vector<ull> ppow(logbp + 2), qpow(logbp + 2);

	ull xp = 1, xq = 1;
	for (int i = 0; i < logbp + 2; ++i) {
		ppow[i] = xp;
		qpow[i] = xq;
		xp *= p;
		xq *= q;
	}

	int sum = 0;
	for (int i = 0; i <= logbp; ++i) {
		for (int j = 0; j < i; ++j) {
			sum += F(i, j, ppow, qpow);
		}
	}

	cout << sum;
}