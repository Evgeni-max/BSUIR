#include "..\functions\functions.h"
#include "..\functions\class.h"
#include <fstream>

void ReadFromFile(worker* a, size_t count, const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    while (!file.eof()) {
        worker temp;
        if (file.read((char*)&temp, sizeof(worker))) {
            // temp.Print()
            if (count == 0) {
                a = (worker*)malloc(sizeof(worker) * (count + 1));
            }
            else {
                a = (worker*)realloc(a, sizeof(worker) * (count + 1));
            }
            a[count] = temp;
        }
        else {
            break;
        }
    }
    file.close();
}