#include <iostream>

extern "C" __declspec(dllexport) double* Create_arr(int n) {
	double* x = new double[n];
	for (int i = 0; i < n; i++) {
		std::cin >> x[i];
	}
	return x;
}

extern "C" __declspec(dllexport) int Count(double* x, int beg, int end) {
	if (end < beg + 1) {
		double a = x[beg] * x[beg] * x[beg];
		if (a < 20 && a > -10) {
			return 1;
		}
		else return 0;
	}
	else {
		return Count(x, beg, (end - beg) / 2 + beg) + Count(x, (end - beg) / 2 + 1 + beg, end);
	}
}
