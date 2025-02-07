#include <iostream>

long long bin_pow(unsigned long long, unsigned long long, unsigned long long);

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