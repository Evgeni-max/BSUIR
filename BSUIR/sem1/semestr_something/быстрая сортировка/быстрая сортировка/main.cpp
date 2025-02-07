//#include <iostream>
//#include <vector>
//
//void QuickSort(std::vector<int>& arr, int start, int end) {
//	if (start == end) return;
//	else if (end == start + 1 ) {
//		return;
//	}
//	else if (end == start + 2) {
//		if (arr[start] > arr[end - 1]) std::swap(arr[start], arr[end - 1]);
//		return;
//	}
//	else {
//		int x = arr[(start + end) / 2];
//		int e = start, g = start, n = start + 1;
//		bool firsttime = true;
//		std::swap(arr[(start + end) / 2], arr[start]);
//
//		for (int i = start; i < end; ++i) {
//			std::cout << arr[i] << ' ';
//		}
//		std::cout << std::endl;
//
//		for (; n < end; ++n) {
//			if (arr[n] == x) {
//				std::swap(arr[n], arr[g]);
//				++g;
//			}
//			else if (arr[n] < x) {
//				std::swap(arr[e], arr[g]);
//				std::swap(arr[e], arr[n]);
//				++e;
//				++g;
//			}
//			else {
//				if (firsttime) {
//					++g;
//					firsttime = false;
//				}
//			}
//
//			for (int i = start; i < end; ++i) {
//				std::cout << arr[i] << ' ';
//			}
//			std::cout << std::endl;
//		}
//
//		for (int i = start; i < end; ++i) {
//			std::cout << arr[i] << ' ';
//		}
//		std::cout << std::endl;
//
//		QuickSort(arr, start, e);
//		QuickSort(arr, g, end);
//	}
//}
//
//int main() {
//	std::vector<int> arr{ -11, -345, -24, -57, -2, -5, -74, 0, -24, -34, -12, -9 };
//
//	for (int i = 0; i < 12; ++i) {
//		std::cout << arr[i] << ' ';
//	}
//	std::cout << std::endl;
//
//	QuickSort(arr, 0, 12);
//
//	for (int i = 0; i < 12; ++i) {
//		std::cout << arr[i] << ' ';
//	}
//}

#include <iostream>
#include <algorithm>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main() {
    int arr[] = { -12, -110, -123, -5, -6, -70, -5, 23, 76, 34, 22, 22, 22, 456, 2, 1, 5, 78};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    std::cout << "Sorted array is \n";
    printArray(arr, n);
}


//#include <iostream>
//
//void MergeSort(int* arr, int start, int end) {
//	if (start == end) return;
//    else if (end == start + 1 ) {
//		return;
//    }
//	else if (end == start + 2) {
//		if (arr[start] > arr[end - 1]) std::swap(arr[start], arr[end - 1]);
//		return;
//	}
//	else {
//		MergeSort(arr, start, (start + end) / 2);
//		MergeSort(arr, (start + end) / 2, end);
//
//		int f = start;
//		int s = (start + end) / 2;
//		int* parr = new int[end - start];
//
//		for (int count = start; count < end; ++count) {
//			if (f == (start + end) / 2) {
//				parr[count - start] = arr[s];
//				++s;
//			}
//			else if (s == end) {
//				parr[count - start] = arr[f];
//				++f;
//			}
//			else if (arr[f] < arr[s]) {
//				parr[count - start] = arr[f];
//				++f;
//			}
//			else {
//				parr[count - start] = arr[s];
//				++s;
//			}
//		}
//
//		for (int count = start; count < end; ++count) {
//			arr[count] = parr[count - start];
//		}
//		delete[] parr;
//	}
//}
//
//int main() {
//	    int arr[] = { 12, 110, 123, 5, 6, 70, 5, 23, 76, 34, 22, 22, 22, 456, 2, 1, 5, 78};
//	    int n = sizeof(arr) / sizeof(arr[0]);
//	
//	    MergeSort(arr, 0, 18);
//	}
//
//#include <vector>
//#include <cmath>
//#include <iostream>
//
//void interpolationSort(std::vector<int>& arr) {
//    int size = arr.size();
//    if (size <= 1) return;
//
//    int min = arr[0];
//    int max = arr[0];
//    for (int i = 1; i < size; i++) {
//        if (arr[i] < min) min = arr[i];
//        else if (arr[i] > max) max = arr[i];
//    }
//
//    if (min != max) {
//        std::vector<std::vector<int>> buckets(size);
//        int interpolation;
//        for (int i = 0; i < size; i++) {
//            interpolation = floor(((arr[i] - min) / static_cast<double>(max - min)) * (size - 1));
//            buckets[interpolation].push_back(arr[i]);
//        }
//
//        int start = 0;
//        for (int i = 0; i < size; i++) {
//            if (buckets[i].size() > 1) {
//                interpolationSort(buckets[i]); // Recursion
//            }
//            for (int j = 0; j < buckets[i].size(); j++) {
//                arr[start++] = buckets[i][j];
//            }
//        }
//    }
//}
//
//int interpolationSearch(std::vector<int>& arr, int x) {
//    int left = 0;
//    int right = arr.size() - 1;
//    while (left <= right && x >= arr[left] && x <= arr[right]) {
//        if (left == right) {
//            if (arr[left] == x) return left;
//            return -1;
//        }
//        int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (x - arr[left]));
//        if (arr[pos] == x)
//            return pos;
//        if (arr[pos] < x)
//            left = pos + 1;
//        else
//            right = pos - 1;
//    }
//    return -1; // элемент не найден
//}
//
//int binarySearch(std::vector<int>& arr, int x) {
//    int left = 0;
//    int right = arr.size() - 1;
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        if (arr[mid] == x)
//            return mid;
//        if (arr[mid] < x)
//            left = mid + 1;
//        else
//            right = mid - 1;
//    }
//    return -1; // элемент не найден
//}
//
//void printArray(std::vector<int> arr, int n) {
//    for (int i = 0; i < n; ++i)
//        std::cout << arr[i] << " ";
//    std::cout << "\n";
//}
//
//int main() {
//    std::vector<int> arr{ 12, 110, 123, 5, 6, 70, 5, 23, 76, 34, 22, 22, 22, 456, 2, 1, 5, 78 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    interpolationSort(arr);
//
//    std::cout << "Sorted array is \n";
//    printArray(arr, arr.size());
//
//    std::cout << binarySearch(arr, 6);
//    std::cout << std::endl;
//    std::cout << interpolationSearch(arr, 6);
//}
