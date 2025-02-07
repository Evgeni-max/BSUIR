#include "..\functions\functions.h"
#include "..\functions\class.h"
#include <fstream>

void EditFile(worker* a, size_t counts, const std::string& filename) {
    int numb;

    while (true) {
        std::cout << "Enter number of struct you want to edit: ";
        numb = checkInputl(1);
        if (numb <= counts) {
            numb--;
            break;
        }
        std::cout << "There is no structures with this number\n";
    }

    std::fstream file;
    file.open(filename, std::ios::binary | std::ios::in | std::ios::out);

    std::cout << "Enter new information: \n";
    worker temp;
    long long bufl;

    char ch;
    const int sizeofchararray = 100;
    int size = sizeofchararray;
    char* nums = new char[size];
    int count = 0;

    while ((ch = getchar()) != '\n') {
        if (ch == ' ') continue;
        else {
            nums[count] = ch;
            count++;
            if (count >= size) {
                size += sizeofchararray;
                nums = (char*)realloc(nums, size * sizeof(char));
            }
        }

    }
    nums[count] = '\0';
    temp.setJob(nums);

    size = sizeofchararray;
    nums = new char[size];
    count = 0;

    while ((ch = getchar()) != '\n') {
        if (ch == ' ') continue;
        else {
            nums[count] = ch;
            count++;
            if (count >= size) {
                size += sizeofchararray;
                nums = (char*)realloc(nums, size * sizeof(char));
            }
        }

    }
    nums[count] = '\0';
    temp.setName(nums);

    std::cin >> bufl;
    temp.setYear(bufl);

    file.seekp(sizeof(worker) * numb, std::ios::beg);
    file.write((char*)&temp, sizeof(worker));
}


void inputN(worker* a, long long start, long long num) {
    resizeArray(a, start + num);

    std::string s;
    std::cout << "Input:\n"
        "1. Name\n"
        "2. Job\n"
        "3. Year of Work\n\n";

    for (long long i = start; i < start + num; i++) {
        std::cout << "Struct " << i << ":\n";
        long long bufl;
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "1: ";

        char ch;
        const int sizeofchararray = 100;
        int size = sizeofchararray;
        char* nums = new char[size];
        int count = 0;
        while ((ch = getchar()) != '\n') {
            if (ch == ' ') continue;
            else {
                nums[count] = ch;
                count++;
                if (count >= size) {
                    size += sizeofchararray;
                    nums = (char*)realloc(nums, size * sizeof(char));
                }
            }

        }
        nums[count] = '\0';
        a[i].setName(nums);

        std::cout << "2: ";

        size = sizeofchararray;
        nums = new char[size];
        count = 0;

        while ((ch = getchar()) != '\n') {
            if (ch == ' ') continue;
            else {
                nums[count] = ch;
                count++;
                if (count >= size) {
                    size += sizeofchararray;
                    nums = (char*)realloc(nums, size * sizeof(char));
                }
            }

        }
        nums[count] = '\0';
        a[i].setJob(nums);

        std::cout << "3: ";

        std::cin >> bufl;
        a[i].setYear(bufl);
    }
}


