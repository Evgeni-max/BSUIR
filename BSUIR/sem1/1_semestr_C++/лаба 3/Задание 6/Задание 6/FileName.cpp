#include <iostream>
#include <math.h>
#include <iomanip>

int main() {
	std::setlocale(LC_ALL, "Russian");

	int k;
	long double mina = 100000, minx, a;

	std::cout << "на сколько частей разделить область поиска корня: ";
	std::cin >> k;
	long double step = 2.0 / k;

	for (long double x = 2; x <= 4; x += step) {
		a = log(x) + 3 * tan(x) + sqrt(x);
		if (abs(mina) > abs(a)) {
			mina = a;
			minx = x;
		}
	}

	std::cout << std::setprecision(20) << "приблизительный корень уравнения: " << minx;

	return 0;
}