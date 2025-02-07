#pragma once

#include <string>

struct remont_house {
	std::string groop;
	std::string marka;
	long long data = 0;
	bool ready = 0;
};

extern remont_house* arr;

void start();

//importDataFromFile
void importData(long long* sizeOfArray);

//viewData
void outputStruct(long long start, long long num);

//deleteData
void deleteData(long long* sizeOfArray);

//exportDataFromFile
void exportData(long long i, remont_house x);

//resize
void resizeArray(long long newSize);

//addData
void inputN(long long start, long long num);
void outputStruct(long long start, long long num);

void maintask(long long sizeofArray);

void sortArray(long long sizeOfArray);
