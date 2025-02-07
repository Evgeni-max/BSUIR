#include <cstdio>
#include "..\CheckInput\chek.h"
#include "..\functions\functions.h"

void outputStruct(long long start, long long num) {
    for (long long i = start; i < start + num; i++) {
        printf("\n\nStruct %lld", i);
        printf("\n0. cost of product:\t\t\t\t");
        printf("%f", a[i].cost);
        printf("\n1. Name of Product:\t\t\t\t\t");
        printf("%s", a[i].name);
        printf("\n2. Count of Products produced:\t\t");
        printf("%lld", a[i].count);
        printf("\n3.0. Data of produsing product:\t\t\t");
        printf("%s", a[i].data);
        printf("\n4. Consumer love this product?:\t\t\t\t");
        printf("%s", a[i].consumer_loves ? "Love" : "Hate");

    }
}