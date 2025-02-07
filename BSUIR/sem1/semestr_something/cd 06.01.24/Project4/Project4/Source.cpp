#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>

struct a {
	int k;
	int b;
	a* j = this;
};

int main() {
	a uj{ 1, 2 };
	a* rt = &uj;
	std::cout << rt->j->j->j;
}