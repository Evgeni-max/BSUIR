#include <iostream>
#include <string>
#include <vector>
#include "..\lab_for_lib7\lib7.h"

int main() {
	int zadanie;
	std::cout << "Enter the number of the problem: ";
	std::cin >> zadanie;

	switch (zadanie) {
	case 1:
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		main1();
		break;
	case 2:
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		main2();
		break;
	case 3:
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		main3();
		break;
	case 4:
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		main4();
		break;
	case 5:
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		main5();
		break;
	case 6:
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		main6();
		break;
	case 7:
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		main7();
		break;
	case 8:
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		main8();
		break;
	case 9:
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		main9();
		break;
	default:
		break;
	}
}