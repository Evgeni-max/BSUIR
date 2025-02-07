#include <iostream>

int** create_arr(int n, int k, bool one) {
	int** x = new int* [n];
	for (int i = 0; i < n; i++) {
		x[i] = new int[k];
	}

	if (one) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				std::cin >> x[i][j];

			}
		}
	}

	return x;
}

int result(int** x, int** b, int n, int k) {
	int end = 0;
	for (int i = 0; i < k; i += 2) {
		for (int j = 0; j < n; j++) {
			if (x[j][i] % 2) {
				b[0][end] = x[j][i];
				end++;
			}
		}

	}

	return end;
}