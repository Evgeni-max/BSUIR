#include <iostream>

int** create_arr(int, int);
void enter_arr(int**, int);
int sum_diagonal(int**, int);
void delete_arr(int**, int);
int getInputNumber();

int main() {
	int n;
	n = getInputNumber();

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