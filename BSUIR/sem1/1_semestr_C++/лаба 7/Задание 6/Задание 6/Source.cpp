#include <iostream>

int main() {
	int n, x;
	std::cin >> n;

	std::cout << "Chose prime number(5, 47, 89):\n";
	std::cin >> x;

	metka:
	switch (x){
	case 5:
		break;
	case 47:
		break;
	case 89:
		break;
	default:
		std::cout << "Its not my number, chose once again:\n";
		std::cin >> x;
		goto metka;
		break;
	}

	int dop = x >> 1;
	++dop;

	while (n > x) {
		n = (n >> 1) + ((n & 1) ? dop : 0);
	}

	if (n == x || n == 0) std::cout << "Yes";
	else std::cout << "No";
}