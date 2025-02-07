#include <iostream>

int** create_arr(int n, int coef) {
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = coef * (i * j - 1);
		}
	}

	return arr;
}

void enter_arr(int** p, int n) {
	int** arr = p;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << arr[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

int sum_diagonal(int** p, int n) {
	int sum = 0;
	int** arr = p;
	for (int i = 0; i < n; i++) {
		sum += arr[i][i];
	}
	return sum;
}

void delete_arr(int** p, int n) {
	int** arr = p;
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
}

int main() {
	int n;
	std::cin >> n;

	int** p3 = create_arr(n, 3);
	int** p2 = create_arr(n, 2);

	std::cout << "First array: \n";
	enter_arr(p3, n);
	std::cout << "His sum of main diagonal: " << sum_diagonal(p3, n) << std::endl;

	std::cout << "Second array: \n";
	enter_arr(p2, n);
	std::cout << "His sum of main diagonal: " << sum_diagonal(p2, n);

	delete_arr(p3, n);
	delete_arr(p2, n);

	return 0;
}