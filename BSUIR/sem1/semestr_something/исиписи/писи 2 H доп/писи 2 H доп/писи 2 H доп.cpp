
#include <iostream>
    using namespace std;
    int main() {
        int y, x, p, q;
        cin >> p >> q;
        x = p;
        y = q;
        while (x != y) {
            if (x > y) {
                x = x - y;
            }
            else {
                y = y - x;
            }
        }
        p = p / x;
        q = q / x;
        std::cout << p << ' ' << q;
    }

