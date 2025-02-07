#include <iostream>

void sort_vstavkami(int* a, int n) {
	for (int index_sort = 0; index_sort < n - 1; ++index_sort) {
        int i = 0;
	    while (a[index_sort - i] >= a[index_sort - i + 1]) {
		    std::swap(a[index_sort - i], a[index_sort - i + 1]);
		    ++i;
	    }
	}
}

int main() {
	std::cout << 3887999997.0 / 89875.0;
	std::cout << '\n' 
		      << 3834000003.0 / 89875.0;
}