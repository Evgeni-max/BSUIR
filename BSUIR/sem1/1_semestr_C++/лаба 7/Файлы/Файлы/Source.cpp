#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::string line;

	std::ifstream out;
	out.open("�����.txt");

	if (out.is_open()) {
		while (std::getline(out, line)) {
			std::cout << line << std::endl;
		}
		
	}
} 