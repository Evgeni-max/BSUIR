#include <iostream>
#include <memory>

int main() {
	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i) {
		int n = 0, lastbuf = 0, nowbuf = 0, countarr = 0, count = 0;
		std::cin >> n;
		std::unique_ptr<int[]> a = std::make_unique<int[]>(n);

		std::cin >> lastbuf;
		for (int i = 1; i < n; ++i) {
			std::cin >> nowbuf;
			
			if (lastbuf < nowbuf) {
				a[countarr] = nowbuf;
				++countarr;
			}
			else {
				lastbuf = nowbuf;
			}
		}

		for (int i = 0; i < n - 1; ++i) {
			if (a[i] < a[i + 1])
				++count;
		}

		std::cout << count << std::endl;
	}
}