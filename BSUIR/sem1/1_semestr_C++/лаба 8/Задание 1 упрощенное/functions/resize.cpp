#include <cstdio>
#include "..\CheckInput\chek.h"
#include "..\functions\functions.h"

void resizeArray(long long newSize) {
	a = (product*)realloc(a, newSize * sizeof(product));
}