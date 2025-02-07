#include <iostream>

int main() {
	int n;
	std::cin >> n;

	int* a = new int[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	bool lastone = 0, result = 1, a0one = 0;
	int beginone, endone, count = 0;

	if (a[0] == 1) {
		a0one = 1;
		lastone = 1;
		++count;
	}
	for (int i = 1; i < n; ++i) {
		if (lastone == 1) {
			if (a[i] != 1) {
				if (a0one == 0) {
                    if (beginone == a[i]) {
						if (count % 2 == 1) {
                           result = 0;
				           break;
						}
						else lastone = 0;
				    }
				    else {
						if (count % 2 == 0) {
							result = 0;
							break;
						}
						else lastone = 0;
				    }
				}
				else {
					a0one = 0;
					lastone = 0;
				}
				
				count = 0;
			}
			else {
				++count;
			}
		}
		else if (a[i] != a[i - 1]) {
			if (a[i] == 1) {
				++count;
				lastone = 1;
				beginone = a[i - 1];
			}
			else {
				result = 0;
				break;
			}
		}
	}

	if (result == 1) std::cout << "Yes";
	else std::cout << "No";
	
}