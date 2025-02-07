#include <cstdio>
#include "..\functions\functions.h"

void sortArray(long long sizeOfArray) {
	bool not_sorted = true;
	while (not_sorted) {
		not_sorted = false;
		for (int i = 0; i < sizeOfArray - 1; ++i) {
			if (arr[i].data < arr[i + 1].data) {
				std::swap(arr[i], arr[i + 1]);
				for (int j = i; j > 0; --j) {
					if (arr[j - 1].data < arr[j].data) {
						std::swap(arr[j - 1], arr[j]);
					}
					else break;
				}
				not_sorted = true;
				break;
			}
		}
	}
}