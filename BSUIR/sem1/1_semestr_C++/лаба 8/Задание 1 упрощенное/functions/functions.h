#pragma once
#include <string>

struct product {
	char name[1000];
	long long count;
	double cost;
	char data[1000];
	bool consumer_loves;
};

extern product* a;

void ok_lets_go(long long* sizeOfArray);
void inputNewStruct(long long start, long long num);
void inputWhile(const std::string& whileWhat, long long* sizeOfArray);
void outputStruct(long long start, long long num);
void resizeArray(long long newSize);
void searchAndDelete(long long* sizeOfArray);
void searchAndEdit(const long long* sizeOfArray);
void searchAndOutput(const long long* sizeOfArray);
void sortArray(long long sizeOfArray);


