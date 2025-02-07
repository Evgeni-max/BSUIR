#include <iostream>

double* create_arr(int n) {
	double* x = new double[n];
	for (int i = 0; i < n; i++) {
		std::cin >> x[i];
	}
	return x;
}

int count(double* x, int beg, int end) {
	if (end < beg + 1) {
		double a = x[beg] * x[beg] * x[beg];
		if (a < 20 && a > -10) {
			return 1;
		}
		else return 0;
	}
	else {
		return count(x, beg, (end - beg) / 2 + beg) + count(x, (end - beg) / 2 + 1 + beg, end);
	}
}


int main() {
	int n;
	std::cin >> n;
	double* x = create_arr(n);

	std::cout << count(x, 0, n - 1);
}
