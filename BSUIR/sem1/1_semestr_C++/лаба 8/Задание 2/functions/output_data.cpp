#include <cstdio>
#include <iostream>
#include <fstream>
#include "..\check_input\check_input.h"
#include "..\functions\functions.h"

std::ifstream in;

void importData(long long* sizeOfArray) {
    *sizeOfArray = 0;
    resizeArray(1);
    in.open("../Task2/files/DB.in");
    while (in) {
        std::string s;
        char c = '1';

        while (in.peek() == '\n') in.get(c);
        if (in.peek() < '0' || in.peek() > '9') break;

        ///resize Array + 1
        (*sizeOfArray)++;
        resizeArray(*sizeOfArray);

        //groop
        std::getline(in, arr[*sizeOfArray - 1].groop);

        ///name
        in.get(c);
        while (in.peek() == '\n') in.get(c);
        std::getline(in, arr[*sizeOfArray - 1].marka);

        ///Input name
        in >> arr[*sizeOfArray - 1].data;

        ///Input year
        in >> arr[*sizeOfArray - 1].ready;
    }

    in.close();
}