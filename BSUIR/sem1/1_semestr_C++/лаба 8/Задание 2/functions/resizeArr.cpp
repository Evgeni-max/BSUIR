#include "..\functions\functions.h"

void resizeArray(long long newSize) {
	if (!(arr = (remont_house*)realloc(arr, newSize * sizeof(remont_house)))) {}
}