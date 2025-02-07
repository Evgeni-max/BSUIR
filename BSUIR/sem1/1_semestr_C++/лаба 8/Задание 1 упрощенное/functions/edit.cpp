#include <cstdio>
#include "..\CheckInput\chek.h"
#include "..\functions\functions.h"

void searchAndEdit(const long long* sizeOfArray) {
    printf("Input number of struct, what u want to edit: \n");

    long long x = checkInputl(1);
    while (x >= *sizeOfArray) {
        printf("Error\n");
        x = checkInputl(x);
    }

    inputNewStruct(x, 1);

}