#include <iostream>

//base ^ p
long long bin_pow(unsigned long long base, unsigned long long p, unsigned long long MOD) {
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

unsigned long long result(int n) {
	if (n == 1) return 1;
	else {
		unsigned long long k = n / 2;
		if (n % 2) {
			return (k + 1) * (k + 1) + result(k);
		}
		else {
			return k * k + result(k);
		}
	}
}