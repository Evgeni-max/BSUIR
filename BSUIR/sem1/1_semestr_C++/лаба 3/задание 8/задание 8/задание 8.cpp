#include <iostream>

int main() {
	long long n, a, b, c, d, e, f, j, h;
	std::cin >> n;

	if (n > 100000000) std::cout << "ERROR";
	else {
		for (int i = 1; i < n + 1; i++) {
			if (i < 10) {
				std::cout << i << std::endl;
			}
			else if (i < 100) {
				a = i % 10;
				b = i / 10;
				if (i == a * a + b * b) std::cout << i << std::endl;
			}
			else if (i < 1000) {
				a = i % 10;
				b = i / 10 % 10;
				c = i / 100;
				if (i == a * a * a + b * b * b + c * c * c) std::cout << i << std::endl;
			}
			else if (i < 10000) {
				a = i % 10;
				b = i / 10 % 10;
				c = i / 100 % 10;
				d = i / 1000;
				if (i == pow(a, 4) + pow(b, 4) + pow(c, 4) + pow(d, 4)) std::cout << i << std::endl;
			}
			else if (i < 100000) {
				a = i % 10;
				b = i / 10 % 10;
				c = i / 100 % 10;
				d = i / 1000 % 10;
				e = i / 10000;
				if (i == pow(a, 5) + pow(b, 5) + pow(c, 5) + pow(d, 5) + pow(e, 5))  std::cout << i << std::endl;
			}
			else if (i < 1000000) {
				a = i % 10;
				b = i / 10 % 10;
				c = i / 100 % 10;
				d = i / 1000 % 10;
				e = i / 10000 % 10;
				f = i / 100000;
				if (i == pow(a, 6) + pow(b, 6) + pow(c, 6) + pow(d, 6) + pow(e, 6) + pow(f, 6))  std::cout << i << std::endl;
			}
			else if (i < 10000000) {
				a = i % 10;
				b = i / 10 % 10;
				c = i / 100 % 10;
				d = i / 1000 % 10;
				e = i / 10000 % 10;
				f = i / 100000 % 10;
				j = i / 1000000;
				if (i == pow(a, 7) + pow(b, 7) + pow(c, 7) + pow(d, 7) + pow(e, 7) + pow(f, 7) + pow(j, 7))  std::cout << i << std::endl;
			}
			else if (i < 100000000) {
				a = i % 10;
				b = i / 10 % 10;
				c = i / 100 % 10;
				d = i / 1000 % 10;
				e = i / 10000 % 10;
				f = i / 100000 % 10;
				j = i / 1000000 % 10;
				h = i / 10000000;
				if (i == pow(a, 8) + pow(b, 8) + pow(c, 8) + pow(d, 8) + pow(e, 8) + pow(f, 8) + pow(j, 8) + pow(h, 8))  std::cout << i << std::endl;
			}
		}
	}

	return 0;
}