#include <iostream>

int partition(int* a, int begin, int end, int x) {
	int left = begin;
	int right = end;

	while(left < right) {
		while (a[left] <= x) {
		    left++;
	    }   
	    while (a[right] > x) {
		    right--;
	    }

		if (left > right) {
			break;
		} 

	    std::swap(a[left], a[right]);
	    left++;
	    right--;


		for (int i = begin; i <= end; i++) {
			std::cout << a[i] << ' ';
		}
		std::cout << std::endl;
	}
	return right;
}




void quicksort(int* a, int begin, int end) {
	if (end > begin) {
		if (end == begin + 1) {
			if (a[end] < a[begin]) {
				std::swap(a[end], a[begin]);
			}
		}
		else {
			int x1 = rand() % (end - begin) + begin;
            int x = a[x1];
		    int p = partition(a, begin, end, x);
		    quicksort(a, begin, p);
		    quicksort(a, p + 1, end);
		}
		
	}
	else {
		return;
	}
}




int main() {
	int n;
	std::cout << "Size of array: ";
	std::cin >> n;

	int* a = new int[n];
	std::cout << "\nArray: \n";

	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

    quicksort(a, 0, n - 1);

	std::cout << "\n\n\n";
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << ' ';
	}
}