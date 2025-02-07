#include <algorithm>
#include <iostream>

int main()
{
    long double a, b, x1, y1, x2, y2, W, H, w, h;
    std::cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

    a = x2 - x1;
    b = y2 - y1;

    long double x;

    if (x1 > x2 && y1 > y2) {
        long double n, m;
        n = x1;
        x1 = x2;
        x2 = n;
        m = y1;
        y1 = y2;
        y2 = m;
    }

    if (a + w > W) {
        if (b + h > H) {
            std::cout << -1; 
            return 0;
        }
        else {
            x = std::min(h - y1, h + y2 - H);
        }
    }
    else {
        if (b + h > H) {
            x = std::min(w - x1, w + x2 - W);
        }
        else {
            x = std::min(std::min(w - x1, w + x2 - W), std::min(h - y1, h + y2 - H));
        }
    }

    if (x < 0) x = 0;
    std::cout << x;

    return 0;
}
