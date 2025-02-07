#include <iostream>
#include <vector>

int main() {
	int t;
	std::cin >> t;

	for (int h = 0; h < t; ++h) {
		long long n, count = 1;
		std::cin >> n;
		std::string a1, a2;
		std::string str;

	    std::cin >> a1;
	    std::cin >> a2;

		str.push_back(a1[0]);
		bool g = 1;
		for (int i = 1; i < n; ++i) {
			if (g && a1[i] <= a2[i - 1]) str.push_back(a1[i]);
			else {
				g = 0;
				str.push_back(a2[i - 1]);
			}
		}
		str.push_back(a2[n - 1]);

		g = 1;
		for (int i = n - 1; i > 0; --i) {
			if (g && a1[i] == a2[i - 1]) {
				++count;
			}
			else if (a1[i] <= a2[i - 1]) {
				g = 0;
			}
		}
		std::cout << str << std::endl;
		std::cout << count << std::endl;
	}
}