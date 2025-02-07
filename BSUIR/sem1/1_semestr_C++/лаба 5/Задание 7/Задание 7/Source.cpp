#include <iostream>

//base ^ p
long long bin_pow(unsigned long long base,  unsigned long long p, unsigned long long MOD) {
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


int main() {
	unsigned long long k, n;
	int t;
	std::cin >> k >> n >> t;
	int count = 0;
	do {
        unsigned long long tt = pow(10, t);
	    k = k % tt;

        std::cout << "Case #" << ++count << ": " << bin_pow(k, n, tt) << std::endl;

		std::cin >> k >> n >> t;
	} while (!(k == 0 && n == 0 && t == 0));
}