#include <iostream>

int** create_arr(int, int, bool);
int result(int** x, int**, int, int);

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