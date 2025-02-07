#include <iostream>
#include <string>

int main() {
	int n, d;
	std::cin >> n >> d;

	std::string dstr = std::to_string(d);

	if (n < dstr.size()) std::cout << "No solution";
	else std::cout << dstr + std::string(n - dstr.size(), '0');
}
