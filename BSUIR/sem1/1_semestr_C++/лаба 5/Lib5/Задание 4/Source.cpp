#include <iostream>

int** create_array(int, int, bool);
void out_return_array(int**, int, int);
void find_0(int**, int, int);
void delete_arr(int**, int);

int main() {
	std::cout << "Give me the size of array: ";

	int n, k;
	std::cin >> n >> k;

	int** a = create_array(n, k, 1);

	find_0(a, n, k);
	out_return_array(a, n, k);
}