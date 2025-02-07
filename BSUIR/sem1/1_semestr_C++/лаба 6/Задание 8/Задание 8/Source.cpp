#include <iostream>
#include <string>

int main() {
	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i) {
		std::string str1, str2, strpolindrom;
		std::cin >> str1 >> str2;
		strpolindrom = str1;

		size_t strlen1 = str1.length();
		size_t strlen2 = str2.length();


		for (int i = strlen1 - 2; i >= 0 ; i--) {
			strpolindrom.push_back(str1[i]);
		}
		std::cout << strpolindrom << std::endl;
		size_t strlenpol = strpolindrom.length();



		bool chek = 0;
		if (str1 == str2) chek = 1;

		while (strlenpol > 2) {
			if (strpolindrom.find(str2) != std::string::npos) {
				chek = 1;
				std::cout << strpolindrom << std::endl;
				break;
			}
			else {
				strpolindrom.erase(strlenpol / 2, 2);
				strlenpol -= 2;
				std::cout << strpolindrom << std::endl;
			}
		}


		if (chek) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}


}

/*
#include <iostream>
#include <string>

int main()
{
	std::string str1, str2;

	int len1, t;
	bool fl = false;
	std::cin >> t;
	for (int j = 0; j < t; j++) {
		std::cin >> str1 >> str2;
		len1 = str1.length();
		fl = false;
		for (int i = len1 - 2; i >= 0; i--) {
			str1 += str1[i];
		}

		fl = (str1.find(str2) != -1);
		for (int i = len1 - 2; i >= 0; i--) {
			if (str1.find(str2) != -1) {
				fl = true;
			}
			str1.erase(i, 2);
		}
		std::cout << (fl ? "YES\n" : "NO\n");
	}
}
*/