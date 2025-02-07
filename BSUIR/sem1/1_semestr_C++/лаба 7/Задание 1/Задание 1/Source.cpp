#include <iostream>
#include <string>

int main() {
	std::string str;
	std::cin >> str;
	
	if (str[0] == 49) {
		size_t length = str.length(); 
	    size_t i = length - 1;

		--str[i];
		while (str[i] < 48) {
			str[i] += 2;
			str[--i] -= 1;
		}
	}

	std::cout << str;
}