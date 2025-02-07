#include <iostream>
#include <Windows.h>

int main() {
	typedef int (*count)(double*, int, int);
	count Count = (count)GetProcAddress(LoadLibrary(L"dinl1.dll"), "Count");

	typedef double* (*create_arr)(int);
	create_arr Create_arr = (create_arr)GetProcAddress(LoadLibrary(L"dinl1.dll"), "Create_arr");

	int n;
	std::cin >> n;
	double* x = Create_arr(n);

	std::cout << Count(x, 0, n - 1);
}