#include <iostream>

unsigned long long result(int);

int main() {
	int k;
	std::cin >> k;

	int* a = new int[k];
	for (int i = 0; i < k; i++) {
		std::cin >> a[i];
	}

	unsigned long long* b = new unsigned long long[k];
	for (int i = 0; i < k; i++) {
		b[i] = result(a[i]);
	}


	for (int i = 0; i < k; i++) {
		std::cout << b[i] << '\n';
	}


	delete[] a;
	delete[] b;
	a = nullptr;
	b = nullptr;
}