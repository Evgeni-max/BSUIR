
#include <iostream>

int main()
{
	double x, name1, name2;
	std::cin >> x;
	name1 = 23 * x * x + 32;
	name2 = name1 * 3 - 88;
	name1 *= x;
	std::cout << name2 + name1 << '\n';
	std::cout << name2 - name1;

	return 0;
}

