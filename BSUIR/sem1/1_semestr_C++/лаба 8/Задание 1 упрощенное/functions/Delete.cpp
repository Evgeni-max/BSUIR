#include <cstdio>
#include "..\CheckInput\chek.h"
#include "..\functions\functions.h"

void deletecost(long long* sizeOfArray);

void deletename(long long* sizeOfArray);

void deletecount(long long* sizeOfArray);

void deletedata(long long* sizeOfArray);

void deleteconsumer_loves(long long* sizeOfArray);

void deleteStructFromArray(long long k, long long* sizeOfArray);

void searchAndDelete(long long* sizeOfArray) {
    printf("What you want to delete?\n0. Nothing\n1. Structures with product cost X\n2. Structures with product Name \"S\"\n3. Structures with product count X\n4. Structures with data of produsing X\n5. Structures with status Love or Not\n");
    long long x = checkInputl(1);
    while (x != 0 && x != 1 && x != 2 && x != 3 && x != 4 && x != 5) {
        printf("Error\n");
        x = checkInputl(x);
    }

    switch (x) {
    case 0:
        return;
    case 1:
        deletecost(sizeOfArray);
        break;
    case 2:
        deletename(sizeOfArray);
        break;
    case 3:
        deletecount(sizeOfArray);
        break;
    case 4:
        deletedata(sizeOfArray);
        break;
    case 5:
        deleteconsumer_loves(sizeOfArray);
        break;
    }
}

void deletecost(long long* sizeOfArray) {
    printf("Input X:\n");
    long long x = checkInputd(1);
    while (x < 0) {
        printf("Error\n");
        x = checkInputd(x);
    }
    for (long long i = 0; i < *sizeOfArray; ++i) {
        if (a[i].cost == x) {
            deleteStructFromArray(i, sizeOfArray);
            i--;
        }
    }
}

void deletename(long long* sizeOfArray) {
    printf("Input S:\n");

    char buf[10000] = "";
    scanf_s("%s", buf, 10000);
    std::string s = buf;

    for (long long i = 0; i < *sizeOfArray; ++i) {
        if (a[i].name == s) {
            deleteStructFromArray(i, sizeOfArray);
            i--;
        }
    }
}

void deletecount(long long* sizeOfArray) {
    printf("Input X:\n");
    long long x = checkInputl(1);
    while (x < 0) {
        printf("Error\n");
        x = checkInputl(x);
    }
    for (long long i = 0; i < *sizeOfArray; ++i) {
        if (a[i].count == x) {
            deleteStructFromArray(i, sizeOfArray);
            i--;
        }
    }
}

void deletedata(long long* sizeOfArray) {
    printf("Input X:\n");

    char buf[10000] = "";
    scanf_s("%s", buf, 10000);
    std::string s = buf;

    for (long long i = 0; i < *sizeOfArray; ++i) {
        if (a[i].data == s) {
            deleteStructFromArray(i, sizeOfArray);
            i--;
        }
    }
}

void deleteconsumer_loves(long long* sizeOfArray) {
    printf("Input status (0 - Hate, 1 - Love:\n");
    long long x = checkInputl(1);

    while (x != 0 && x != 1) {
        printf("Error");
        x = checkInputl(x);
    }

    for (long long i = 0; i < *sizeOfArray; ++i) {
        if (a[i].consumer_loves == x) {
            deleteStructFromArray(i, sizeOfArray);
            i--;
        }
    }
}

void deleteStructFromArray(long long k, long long* sizeOfArray) {
    for (long long i = k; i < (*sizeOfArray) - 1; i++) {
        product tmp = a[i + 1];
        a[i + 1] = a[i];
        a[i] = tmp;
    }
    (*sizeOfArray)--;
    resizeArray(*sizeOfArray);
}