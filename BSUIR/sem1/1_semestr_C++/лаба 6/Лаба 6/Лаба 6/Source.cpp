#include <iostream>
#include <string>
#include <cstring>
#include "..\Lib_for_Lab\LABA.h";

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
		   main5();
		   break;
	   case 6:
		   main6();
		   break;
	   case 7:
		   main7();
		   break;
	   case 8:
		   main8();
		   break;
	   default:
		   break;
	}
}