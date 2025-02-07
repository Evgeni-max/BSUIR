#include <cstdio>
#include <iostream>
#include "..\check_input\check_input.h"
#include "..\functions\functions.h"

void deleteData(long long* sizeOfArray) {
    long long x;
    std::cout << "Input N:(" << 0 << " - " << *sizeOfArray - 1 << ")\n";
    x = checkInputl(1);
    while (x < 0 || x >= *sizeOfArray) {
        std::cout << "Error\n";
        x = checkInputl(1);
    }

    for (long long i = x; i < (*sizeOfArray) - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*sizeOfArray)--;
    resizeArray(*sizeOfArray);

}