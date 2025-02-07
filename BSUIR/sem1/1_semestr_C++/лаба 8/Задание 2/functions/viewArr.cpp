#include <cstdio>
#include <iostream>
#include "..\check_input\check_input.h"
#include "..\functions\functions.h"

void outputStruct(long long start, long long num) {
    for (long long i = start; i < start + num; i++) {
        std::cout << "Struct " << i << ":"
            << "\ngroop: " << arr[i].groop
            << "\nmarka: " << arr[i].marka
            << "\ndata: " << arr[i].data
            << "\nready: " << arr[i].ready << "\n\n";
    }
}