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

int main() {
	int n, k;
	std::cin >> n >> k;

	int** x = create_arr(n, k, 1);
	int** b = create_arr(1, k * k, 0);

	int end = result(x, b, n, k);
	if (end == 0) {
		std::cout << "We dont have such elements.";
	}
	else {
		double pr = 0;
		std::cout << "Our array: \n";
		for (int i = 0; i < end; i++) {
			std::cout << b[0][i] << ' ';
			pr += b[0][i];
		}

		std::cout << "\nsum = " << pr / end;
	}
}