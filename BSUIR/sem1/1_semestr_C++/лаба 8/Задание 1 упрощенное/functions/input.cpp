#include "..\CheckInput\chek.h"
#include <cstdio>
#include <string>
#include "..\functions\functions.h"

void inputNewStruct(long long start, long long num) {
    printf("Struct include:\n"
        "0. cost of product\n"
        "1. Name of Product\n"
        "2. Count of Products produced\n"
        "3. Data of produsing product\n"
        "4. Consumer love this product? (0 - Hate. 1 - Love)\n\n");
    for (long long i = start; i < start + num; i++) {
        printf("Input struct %lld:\n0: ", i);
        a[i].cost = checkInputd(a[i].cost);
        while (a[i].cost < 0) {
            printf("Error\n");
            a[i].cost = checkInputd(a[i].cost);
        }

        printf("1: ");
        scanf_s("%s", a[i].name, 1000);

        printf("2: ");
        a[i].count = checkInputl(a[i].count);
        while (a[i].count <= 0) {
            printf("Error\n");
            a[i].count = checkInputl(a[i].count);
        }


        printf("3: ");
        scanf_s("%s", a[i].data, 1000);

        printf("4: ");
        while (true) {
            long long x = checkInputl(1);
            if (x == 0 || x == 1) {
                a[i].consumer_loves = (bool)x;
                break;
            }
            else {
                printf("Error\n");
            }
        }
    }
}

void inputWhile(const std::string& whileWhat, long long* sizeOfArray) {
    printf("Struct include:\n0. cost of product\n1. Name of Product\n2. count of Products produced\n3. data of produsing product\n4. Is product loved by consumers (0 - Hate. 1 - Love)\n\n");
    do {
        (*sizeOfArray)++;
        resizeArray(*sizeOfArray);

        printf("Input struct %lld:\n0: ", *sizeOfArray - 1);
        a[*sizeOfArray - 1].cost = checkInputl(a[*sizeOfArray - 1].cost);
        while (a[*sizeOfArray - 1].cost < 0) {
            printf("Error\n0: ");
            a[*sizeOfArray - 1].cost = checkInputl(a[*sizeOfArray - 1].cost);
        }

        printf("1: ");
        scanf_s("%s", a[*sizeOfArray - 1].name, 1000);

        printf("2: ");
        a[*sizeOfArray - 1].count = checkInputl(a[*sizeOfArray - 1].count);
        while (a[*sizeOfArray - 1].count <= 0) {
            printf("Error\n2: ");
            a[*sizeOfArray - 1].count = checkInputl(a[*sizeOfArray - 1].count);
        }

        printf("3: ");
        scanf_s("%s", a[*sizeOfArray - 1].data, 1000);


        while (true) {
            printf("4: ");
            long long x = checkInputl(1);
            if (x == 0 || x == 1) {
                a[*sizeOfArray - 1].consumer_loves = (bool)x;
                break;
            }
            else {
                printf("Error\n");
            }
        }
    } while (a[*sizeOfArray - 1].name != whileWhat);
}