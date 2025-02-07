
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    double x1, y1, r, x2, y2, R, length;
    std::cin >> x1 >> y1 >> r >> x2 >> y2 >> R;

    length = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    if (length <= abs(R - r)) {
        if (R > r) std::cout << "Да";
        else std::cout << "Да, но справедливо обратное для двух фигур";
    }
    else if (length < R + r) {
        std::cout << "Фигуры пересекаются";
    }
    else std::cout << "Ни одно условие не выполнено";

    return 0;
}

