#include <iostream>
#include <string>

int main()
{
    unsigned int word_counter = 0;
    int *a = new int[10000];

    while (std::cin >> a[word_counter]) {
        word_counter++;
    }

    //max
    int max = a[0], imax = 0;
    for (int i = 1; i < word_counter; i++) {
        if (max < a[i]) {
            max = a[i];
            imax = i;
        }
    }

    //min
    int min = a[0], imin = 0;
    for (int i = 1; i < word_counter; i++) {
        if (min > a[i]) {
            min = a[i];
            imin = i;
        }
    }

    //0
    if (imin < imax) {
        for (int i = imin + 1; i < imax; i++) {
            a[i] = 0;
        }
    }
    else {
        for (int i = imax + 1; i < imin; i++) {
            a[i] = 0;
        }
    }

    int cnt0 = 0;
    for (int i = 0; i < word_counter; i++) {
        if (a[i] == 0) cnt0++;
    }

    if (word_counter / 2 < cnt0) {
        for (int i = 0; i < word_counter; i++) {
            if (a[i] != 0) std::cout << a[i] << ' ';
        }
    }
    else {
        for (int i = 0; i < word_counter; i++) {
            std::cout << a[i] << ' ';
        }
    }
     
    delete[] a;
    a = nullptr;

    return 0;
}
