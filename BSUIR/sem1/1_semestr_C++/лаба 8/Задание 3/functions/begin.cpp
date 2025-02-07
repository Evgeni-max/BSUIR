#include "..\functions\functions.h"
#include "..\functions\class.h"
#include <iostream>

void start() {
    long long x;
    worker* a = new worker[0];
    size_t sizeOfArray = 0;

    while (true) {
        std::cout
            << "Select what to do:\n"
            // "1. Initialize data from DB.in (will delete all data)\n"
            "2. Add N new class to DB\n"
            "3. Delete class with number N\n"
            "4. Edit class with number N\n"
            "5. View classes from DB\n"
            "0. Exit\n";

        x = checkInputl(1);
        switch (x) {
            /*case 1:
                importData(&sizeOfArray);
                outputStruct(0, sizeOfArray);
                break;*/
        case 2:
            long long N;
            std::cout << "Input N:\n";
            N = checkInputl(1);
            inputN(a, sizeOfArray, N);
            sizeOfArray += N;
            break;
        case 3:
            if (sizeOfArray == 0) {
                std::cout << "Error - 0 structs left\n";
                continue;
            }
            int numb;
            std::cout << "N:\n";
            std::cin >> numb;
            deleteArray(a, numb, sizeOfArray, "text.txt");
            break;
        case 4:
            if (sizeOfArray == 0) {
                std::cout << "Error - 0 structs left\n";
                continue;
            }
            std::cout << "N:\n";
            std::cin >> numb;

            EditFile(a, sizeOfArray, "text.txt");
            break;
        case 5:
            if (sizeOfArray == 0) {
                std::cout << "Error - 0 structs left\n";
                continue;
            }
            outputStruct(a, 0, sizeOfArray);
            break;
        default:
            continue;
        }
    }
}