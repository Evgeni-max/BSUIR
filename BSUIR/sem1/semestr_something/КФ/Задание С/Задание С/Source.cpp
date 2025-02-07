#include <iostream>
#include <string>

int main() {
	std::string str, glas = "aouyie";
	size_t length;
	std::cin >> length >> str;


	bool last = 0, now = 0; //1 - согласная, 0 - гласная 
	last = glas.find(str[0]) == std::string::npos;
	int count = 1, result = 0;
	bool word = 0;

	for (int i = 1; i < length; ++i) {
		now = glas.find(str[i]) == std::string::npos;

		if (now == last) {
			count++;
		}
		else {
			if (word == 1) {
				if (count == 1) {
					word = 0;
				}
				++result;
			}
			else word = 1;

			count = 1;
		}

		last = now;
	}

	if (word == 1) ++result;

	std::cout << result;
}