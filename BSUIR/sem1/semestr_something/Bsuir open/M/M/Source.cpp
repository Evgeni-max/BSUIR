#include <iostream>

int main() {
	
	std::string corStr = "BSUIROPEN", str;
	std::cin >> str;

	bool string_is_find = true;

	for (int i = 0; i < 9; ++i) {
		if (str.find(corStr[i]) == std::string::npos)
		{
			string_is_find = false;
		}
	}

	if (string_is_find) {
		int siz = str.size() - 9, count = 0;

		while (siz > 0) {
			count += siz % 2;
			siz /= 2;
		}

        std::cout << count;
	}
	else
		std::cout << -1;
}