#include <cstdio>
#include <iostream>
#include "..\check_input\check_input.h"
#include "..\functions\functions.h"

void inputN(long long start, long long num) {
    std::string s;
    std::cout << "Input:\n"
        "1. Groop of things\n"
        "2. name\n"
        "3. data of producing\n"
        "4. Ready or not\n";

    for (long long i = start; i < start + num; i++) {
        std::cout << "Struct " << i << ":\n";

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "1: ";
        std::getline(std::cin, arr[i].groop);

        std::cout << "2: ";
        std::getline(std::cin, arr[i].marka);

        std::cout << "3: ";
        arr[i].data = checkInputl(1);

        std::cout << "4: ";
        arr[i].ready = checkInputl(1);
    }
}