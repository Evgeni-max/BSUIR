#include <iostream>
#include <vector>
using namespace std;
int main() {

	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	double k1, b1, k2, b2, k3, b3;

	k1 = (y1 - y2) / (x1 - x2);
	b1 = (x1 * y2 - x2 * y1) / (x1 - x2);

	k2 = (y3 - y2) / (x3 - x2);
	b2 = (x3 * y2 - x2 * y3) / (x3 - x2);

	k3 = (y1 - y3) / (x1 - x3);
	b3 = (x1 * y3 - x3 * y1) / (x1 - x3);

	bool ish1, ish3, ish2;
	ish1 = x3 * k1 + b1 < y3;
	ish2 = x1 * k2 + b2 < y1;
	ish3 = x2 * k3 + b3 < y2;

	double x, y;
	cin >> x >> y;

	bool ishx1, ishx2, ishx3;
	bool iseq1, iseq2, iseq3;
	ishx1 = x * k1 + b1 < y;
	ishx2 = x * k2 + b2 < y;
	ishx3 = x * k3 + b3 < y;

	iseq1 = x * k1 + b1 == y;
	iseq2 = x * k1 + b1 == y;
	iseq3 = x * k1 + b1 == y;

	if ((iseq1 || ish1 == ishx1) && (iseq2 || ish2 == ishx2) && (iseq3 || ish3 == ishx3)) cout << "in";
	else cout << "out";
}