#include <iostream>
#include <cstring>
#include <string>

bool check_polindrom(std::string& str) {
	size_t lenght = str.length();
	size_t lenght1 = lenght - 1;
	size_t halflenght = lenght / 2;
	for (int i = 0; i < halflenght; ++i) {
		if (str[i] != str[lenght1 - i]) {
			return 0;
		}
	}
	return 1;
}

bool check_string_of_equal_numbers(std::string& str) {
	size_t lenght1 = str.length() - 1;
	for (int i = 0; i < lenght1; ++i) {
		if (str[i] != str[i + 1]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	std::string str; 
	std::cout << "Give me str: ";
	std::cin >> str;
    size_t lenght = str.length();

	if (check_polindrom(str)) {
		if (check_string_of_equal_numbers(str)) std::cout << -1;
		else std::cout << lenght - 1;
	}
	else std::cout << lenght;
}