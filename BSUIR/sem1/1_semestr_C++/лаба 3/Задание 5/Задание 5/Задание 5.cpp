
#include <iostream>
#include <iomanip>

int main()
{
    setlocale(LC_ALL, "Russian");

    int n, amount;
    std::cout << "Кол-во членов ряда: ";
    std::cin >> n;
    std::cout << "Кол-во чисел ввода: ";
    std::cin >> amount;

    double x, sum;
    for (int i = 0; i < amount; i++) {

        std::cin >> x;
        sum = 1;
        double x1 = 1;

        for (int j = 1; j < n + 1; j++) {
            x1 *= x * x / 2 / j / (2 * j - 1);
            sum += x1;
        }

        std::cout << std::setprecision(20) << sum << ' ' << (exp(x) + exp(-x)) / 2 << '\n';
    }

    return 0;
}
