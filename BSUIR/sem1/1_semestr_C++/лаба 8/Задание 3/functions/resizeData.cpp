#include "..\functions\functions.h"
#include "..\functions\class.h"

void resizeArray(worker* a, long long newSize) {
	a= (worker*)realloc(a, newSize * sizeof(worker));
}