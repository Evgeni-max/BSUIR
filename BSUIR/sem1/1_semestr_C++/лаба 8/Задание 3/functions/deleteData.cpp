#include "..\functions\functions.h"
#include "..\functions\class.h"
#include <fstream>

void deleteArray(worker* a, size_t numb, size_t count, const std::string& filename) {
    std::fstream file;
    file.open(filename, std::ios::binary | std::ios::in | std::ios::out);
    file.seekp(sizeof(worker) * count, std::ios::beg);

    worker temp;
    file.read((char*)&temp, sizeof(worker));

    file.seekp(sizeof(worker) * numb, std::ios::beg);
    file.write((char*)&temp, sizeof(worker));

    a = (worker*)realloc(a, count - 1);

}