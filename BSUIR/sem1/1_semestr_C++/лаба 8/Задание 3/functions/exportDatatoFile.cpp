#include "..\functions\functions.h"
#include "..\functions\class.h"
#include <fstream>

void WriteToFile(worker* a, size_t count, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    for (size_t i = 0; i < count; ++i) {
        file.write((char*)&a[i], sizeof(worker));
    }
    file.close();
}