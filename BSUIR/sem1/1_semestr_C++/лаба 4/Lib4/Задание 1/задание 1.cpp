// Вариант 2

#include <iostream>

int main()
{
    int k;
    std::cin >> k;

    //int degree = k < 10000 ? k < 1000 ? k < 100 ? k < 10 ? 1 : 2 : 3 : 4 : 5;
    
    //if (degree == 5) const int size = 100000;
    //else if (degree == 4) const int size = 10000;
    //else if (degree == 3) const int size = 1000;
    //else if (degree == 2) const int size = 100;
    //else const int size = 10;

    int arr[10000];

    for (int i = 0; i < k; i++) {
        std::cin >> arr[i];
    }
    for (int i = k - 1; i >= 0; i--) {
        std::cout << arr[i] << ' ';
    }
}

