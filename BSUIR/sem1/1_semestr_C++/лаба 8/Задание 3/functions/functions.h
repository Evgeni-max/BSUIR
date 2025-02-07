#pragma once

#include <string>
#include <iostream>
#include "..\checkInput\chekInput.h"
#include "..\functions\class.h"

extern FILE* f;

void start();
void resizeArray(worker* a, long long newSize);
void deleteArray(worker* a, size_t numb, size_t count, const std::string& filename);
void EditFile(worker* a, size_t count, const std::string& filename);
void outputStruct(worker* a, long long start, long long num);
void inputN(worker* a, long long start, long long num);
