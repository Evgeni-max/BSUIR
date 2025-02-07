#include <iostream>

int main() {
	long long n, st, r;
	std::cin >> n;
	char buf;
	std::cin >> buf >> st >> r;


	if (buf == 'H') {
		if (r == 1 || r == st) {
			std::cout << 3 * st - 1;
		}
		else
			std::cout << 0;
	} 
	else {
		r = (r + 1) / 2;
		std::cout << r * (st - r + 1) * 3 - 2;
	}

}



//long long bin_pow(unsigned long long base, unsigned long long p, unsigned long long MOD) {
//	if (p == 0) {
//		return 1;    //Выход из рекурсии.
//	}
//
//	if (p == 1) {
//		return base;    //Выход из рекурсии.
//	}
//
//	long long t = bin_pow(base, p / 3, MOD);
//	long long tt = (t * t % MOD) * t % MOD;
//
//	/*if (p % 3 == 0) {
//		return tt;
//	}
//	else if (p % 3 == 1){
//		return tt * base % MOD;
//	}
//	else if (p % 3 == 2) {
//		return tt * (base * base % MOD) % MOD;
//	}
//	else {
//		return tt * ((base * base % MOD) * base % MOD) % MOD;
//	}*/
//
//	switch (p % 3) {
//	case 0:
//		return tt;
//		break;
//	case 1:
//		return tt * base % MOD;
//		break;
//	case 2:
//		return tt * (base * base % MOD) % MOD;
//		break;
//	}
//}