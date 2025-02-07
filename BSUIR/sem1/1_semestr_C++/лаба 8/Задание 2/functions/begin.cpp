#include <cstdio>
#include <iostream>
#include "..\check_input\check_input.h"
#include "..\functions\functions.h"

void start() {
    long long sizeOfArray = 0;
    arr = (remont_house*)calloc(sizeof(remont_house), 1);
    long long x;
    while (true) {
        std::cout
            << "\nSelect what to do:\n"
            "1. Initialize data from file.in\n"
            "2. Add N new structs to file\n"
            "3. Delete struct with number N\n"
            "4. Edit struct with number N\n"
            "5. View structures from file\n"
            "6. Do task and end program\n"
            "0. Exit\n";

        x = checkInputl(1);
        switch (x) {
        case 1:
            importData(&sizeOfArray);
            outputStruct(0, sizeOfArray);
            break;
        case 2:
            long long N;
            std::cout << "Input N:\n";
            N = checkInputl(1);
            resizeArray(sizeOfArray + N);
            inputN(sizeOfArray, N);
            sizeOfArray += N;
            break;
        case 3:
            if (sizeOfArray == 0) {
                std::cout << "Error - 0 structs left\n";
                continue;
            }
            deleteData(&sizeOfArray);
            break;
        case 4:
            if (sizeOfArray == 0) {
                printf_s("Error - 0 structs left\n");
                continue;
            }
            long long ye;
            std::cout << "Input N(" << 0 << " - " << sizeOfArray - 1 << "):\n";
            ye = checkInputl(1);
            while (ye < 0 || ye >= sizeOfArray) {
                std::cout << "Error\n";
                ye = checkInputl(ye);
            }
            inputN(ye, 1);
            break;
        case 5:
            if (sizeOfArray == 0) {
                printf_s("Error - 0 structs left\n");
                continue;
            }
            outputStruct(0, sizeOfArray);
            break;
        case 6:
            if (sizeOfArray == 0) {
                printf("Error - 0 structs left\n");
                continue;
            }
            maintask(sizeOfArray);
            return;
        case 0:
            return;
        default:
            break;
        }
    }
}