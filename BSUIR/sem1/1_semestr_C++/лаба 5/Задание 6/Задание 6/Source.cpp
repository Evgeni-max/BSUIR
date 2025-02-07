#include <iostream>

long long f(long long x) {
	long long k = x % 10;
	if (k) return k;
	else {
		if (x == 0) return 0;
		else return f(x / 10);
	}
}

long long result(long long p, long long q) {
	long long result = 0;
	q = q + 1;
	for (long long i = p; i < q; i++) {
		result += f(i);
	}
	return result;
}

int main() {
	long long p, q;
	std::cin >> p >> q;

	while (p >= 0 && q >= 0) {
		std::cout << result(p, q) << '\n';
		std::cin >> p >> q;
	}
}