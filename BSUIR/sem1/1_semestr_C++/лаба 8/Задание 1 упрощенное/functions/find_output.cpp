#include <cstdio>
#include "..\CheckInput\chek.h"
#include "..\functions\functions.h"

void searchcost(long long sizeOfArray);

void searchname(long long sizeOfArray);

void searchcount(long long sizeOfArray);

void searchdata(long long sizeOfArray);

void searchconsumer_loves(long long sizeOfArray);

void searchAndOutput(const long long* sizeOfArray) {
    printf("What you want to search?\n0. Nothing\n1. Structures with product cost X\n2. Structures with product Name \"S\"\n3. Structures with product count X\n4. Structures with data of produsing X\n5. Structures with status Love or Not\n");
    long long x = checkInputl(1);
    while (x != 0 && x != 1 && x != 2 && x != 3 && x != 4 && x != 5) {
        printf("Error");
        x = checkInputl(x);
    }

    switch (x) {
    case 0:
        return;
    case 1:
        searchcost(*sizeOfArray);
        break;
    case 2:
        searchname(*sizeOfArray);
        break;
    case 3:
        searchcount(*sizeOfArray);
        break;
    case 4:
        searchdata(*sizeOfArray);
        break;
    case 5:
        searchconsumer_loves(*sizeOfArray);
        break;
    }
}

void searchcost(long long sizeOfArray) {
    printf("Input X:\n");
    long long x = checkInputd(1);
    while (x < 0) {
        printf("Error\n");
        x = checkInputd(x);
    }

    for (long long i = 0; i < sizeOfArray; ++i) {
        if (a[i].cost == x) {
            outputStruct(i, 1);
        }
    }
}

void searchname(long long sizeOfArray) {
    printf("Input S:\n");

    char buf[10000] = "";
    scanf_s("%s", buf, 10000);
    std::string s = buf;

    for (long long i = 0; i < sizeOfArray; ++i) {
        if (a[i].name == s) {
            outputStruct(i, 1);
        }
    }
}

void searchcount(long long sizeOfArray) {
    printf("Input X:\n");
    long long x = checkInputl(1);
    while (x < 0) {
        printf("Error\n");
        x = checkInputl(x);
    }
    for (long long i = 0; i < sizeOfArray; ++i) {
        if (a[i].count == x) {
            outputStruct(i, 1);
        }
    }
}

void searchdata(long long sizeOfArray) {
    printf("Input X:\n");

    char buf[10000] = "";
    scanf_s("%s", buf, 10000);
    std::string s = buf;

    for (long long i = 0; i < sizeOfArray; ++i) {
        if (a[i].data == s) {
            outputStruct(i, 1);
        }
    }
}

void searchconsumer_loves(long long sizeOfArray) {
    printf("Input status (0 - Hate, 1 - Love:\n");
    long long x = checkInputl(1);

    while (x != 0 && x != 1) {
        printf("Error");
        x = checkInputl(x);
    }

    for (long long i = 0; i < sizeOfArray; ++i) {
        if (a[i].consumer_loves == x) {
            outputStruct(i, 1);
        }
    }
}