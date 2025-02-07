#include <iostream>

long long f(long long);
long long result(long long, long long);

int main() {
	long long p, q;
	std::cin >> p >> q;

	while (p >= 0 && q >= 0) {
		std::cout << result(p, q) << '\n';
		std::cin >> p >> q;
	}
}