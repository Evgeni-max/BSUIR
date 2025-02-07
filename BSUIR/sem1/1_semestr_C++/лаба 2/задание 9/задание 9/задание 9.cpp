
#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Russian");

    double a, x, z, fix;
    int sw;

    std::cin >> z >> a;

    if (z < 1) x = z * z;
    else x = z + 1;

    std::cout << "Если sw = 1, fix = 2x\nЕсли sw = 2, fix = x^3\nВ остальных случаях fix = x/3\nВведите число sw:";
    std::cin >> sw;
    switch (sw) {
       case 1:
           fix = 2 * x;
           break;
       case 2:
           fix = x * x * x;
           break;
       default:
           fix = x / 3;
           break;
           
    }
    std::cout << a * log(1 + pow(x, 0.2)) + pow(cos((int)(fix + 1)), 2) << '\n';
    std::cout << (int)(fix + 1);

    return 0;

}

