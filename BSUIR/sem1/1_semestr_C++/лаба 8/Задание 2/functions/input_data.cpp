#include <cstdio>
#include <iostream>
#include <fstream>
#include "..\check_input\check_input.h"
#include "..\functions\functions.h"

std::ofstream out;

void exportData(long long i, remont_house x) {
	out.open("text.txt");

    out << "Struct " << i << ":"
        << "\ngroop: " << x.groop
        << "\nmarka: " << x.marka
        << "\ndata: " << x.data
        << "\nready: " << x.ready << "\n\n";

    out.close();
}