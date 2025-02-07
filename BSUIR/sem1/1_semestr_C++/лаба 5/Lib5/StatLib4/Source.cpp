#include <iostream>

int** create_array(int n, int k, bool bol) {
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[k];
	}
	if (bol) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				//a[i][j] = rand() - 10000;
				std::cin >> a[i][j];
			}
		}
	}

	return a;
}

void delete_arr(int** a, int n) {
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
	a = nullptr;
}

void out_return_array(int** a, int n, int k) {
	int** b = create_array(n, k, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			b[i][j] = a[n - 1 - i][k - 1 - j];
		}
	}
	std::cout << "return array: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			std::cout << b[i][j] << '\t';
		}
		std::cout << std::endl;
	}

	delete_arr(b, n);
}


void find_0(int** a, int n, int k) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (a[i][j] == 0) {
				count++;
				std::cout << '(' << i << ',' << j << ')';
			}
		}
	}
	std::cout << std::endl << "Total number of 0 elements: " << count << '\n';
}

