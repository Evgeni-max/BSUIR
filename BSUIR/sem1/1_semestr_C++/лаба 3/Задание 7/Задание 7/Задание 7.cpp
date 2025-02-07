#include <iostream>
#include <iomanip>
#include <algorithm>

int main()
{
    std::cout << std::setprecision(20) << "GIVE YOUR FUCKING X, NOW! \n ";

    long double x;

    while (!(std::cin >> x) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "ERROR";
    }

    //sin x
    long double x1 = x, pi = acos(-1);

    if (x1 > 0) {
       while (x1 > 2 * pi) {
          x1 -= 2 * pi;
       }
    }
    else {
        while (x1 < -2 * pi) {
            x1 += 2 * pi;
        }
    }

    long double st = x1, sinx = x1, b = -x1 * x1;

    for (int i = 3; i != 81; i += 2) {
        st *= b / (i - 1) / i;
        sinx += st;
    }

    //cos x
    long double cosx = 1, step = 1;

    for (int j = 2; j != 80; j += 2) {
        step *= -x1 * x1 / j / (j - 1);
        cosx += step;
    }

    //ln x
    long double stepik = -1, lnx = 0, c = fabs(x);
    int j = 0;
    
    while (c >= 2) {
        c /= 2.71828182846;
        j++;
    }

    long double c1 = c - 1;

    for (int i = 1; i != 1000; i++) {
        stepik *= c1 / -i;
        lnx += stepik;
    }
    
    std::cout << "GET YOUR FUCKING MIN! " << std::min(std::min(sinx, cosx), lnx + j) << '\n';
    std::cout << sinx << ' ' << cosx << ' ' << lnx + j;

    return 0;
}

