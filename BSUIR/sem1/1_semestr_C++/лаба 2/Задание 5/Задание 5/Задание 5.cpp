#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double k, x, y;
    std::cin >> k >> x >> y;
    std::cout << std::setprecision(22);
    if (k == 0 && x == 0 && y == 0) std::cout << 0;
    else {
        if (k > 0) {
            bool posy1 = y >= 0, posy2 = (y <= k), posx1 = x >= 0, posx2 = x <= k;
            if (posy1) {
                if (posy2) {
                    if (posx1) {
                        if (posx2) {
                            std::cout << std::min(std::min(x, k - x), std::min(y, k - y));
                        }
                        else std::cout << x - k;
                    }
                    else std::cout << -x;
                }
                else {
                    if (posx1) {
                        if (posx2) {
                            std::cout << y - k;
                        }
                        else std::cout << std::sqrt((x - k) * (x - k) + (y - k) * (y - k));
                    }
                    else std::cout << sqrt(x * x + (y - k) * (y - k));
                }
            }
            else {
                if (posx1) {
                    if (posx2) {
                        std::cout << -y;
                    }
                    else std::cout << sqrt((x - k) * (x - k) + y * y);
                }
                else std::cout << sqrt(x * x + y * y);
            }
        }
        else {
            bool posy1 = y <= 0, posy2 = (y >= k), posx1 = x <= 0, posx2 = x >= k;
            if (posy1) {
                if (posy2) {
                    if (posx1) {
                        if (posx2) {
                            std::cout << std::min(std::min(-x, -k + x), std::min(-y, -k + y));
                        }
                        else std::cout << -x + k;
                    }
                    else std::cout << x;
                }
                else {
                    if (posx1) {
                        if (posx2) {
                            std::cout << -y + k;
                        }
                        else std::cout << sqrt((x - k) * (x - k) + (y - k) * (y - k));
                    }
                    else std::cout << sqrt(x * x + (y - k) * (y - k));
                }
            }
            else {
                if (posx1) {
                    if (posx2) {
                        std::cout << y;
                    }
                    else std::cout << sqrt((x - k) * (x - k) + y * y);
                }
                else std::cout << sqrt(x * x + y * y);
            }

        }
    }
    return 0;
}
