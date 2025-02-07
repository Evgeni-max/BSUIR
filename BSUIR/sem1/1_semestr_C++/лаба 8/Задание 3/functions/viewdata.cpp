#include <iostream>
#include "..\checkInput\chekInput.h"
#include "..\functions\class.h"

void outputStruct(worker* a, long long start, long long num) {
    for (long long i = start; i < start + num; i++) {
        std::cout << "Struct " << i << ":"
            << "\njob: " << a[i].getJob()
            << "\nname: " << a[i].getName()
            << "\nyear of work: " << a[i].getYear() << "\n\n";
    }
}