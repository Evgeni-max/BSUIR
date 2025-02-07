#include <cstdio>
#include <iostream>
#include "..\check_input\check_input.h"
#include "..\functions\functions.h"

void maintask(long long sizeofArray) {
	bool at_least_one = false;
	std::string group_find;
	std::cout << "Enter name of group:\n";
	getline(std::cin, group_find);

	for (int i = 0; i < sizeofArray; ++i) {
		if (arr[i].groop == group_find) {
			at_least_one = true;
			std::cout << "\nmarka: " << arr[i].marka
				      << "\nready: " << arr[i].ready << "\n\n";
		}
	}

	if (!at_least_one) std::cout << "There is no such stucts.";
}