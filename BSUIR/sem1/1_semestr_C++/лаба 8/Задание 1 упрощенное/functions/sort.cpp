#include <cstdio>
#include "..\CheckInput\chek.h"
#include "..\functions\functions.h"

void sortArray(long long sizeOfArray) {
	bool not_sorted = true;
	while (not_sorted) {
		not_sorted = false;
		for (int i = 0; i < sizeOfArray - 1; ++i) {
			if (a[i].cost < a[i + 1].cost) {
				std::swap(a[i], a[i + 1]);
				for (int j = i; j > 0; --j) {
					if (a[j - 1].cost < a[j].cost) {
						std::swap(a[j - 1], a[j]);
					}
					else break;
				}
				not_sorted = true;
				break;
			}
		}
	}
}