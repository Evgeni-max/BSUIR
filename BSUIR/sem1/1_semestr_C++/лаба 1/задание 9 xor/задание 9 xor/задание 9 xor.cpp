
#include <iostream>
#include <climits>

int main()
{
    setlocale(LC_ALL, "Russian");

    int a, b;
    std::cin >> a >> b;
    std::cout << " число в ячейке памяти а до программы = " << a << "\n число в ячейке памяти b до программы = " << b;

    a = a ^ b;
    b = b ^ a;
    a = a ^ b;

    std::cout << "\n число в ячейке памяти а после программы = " << a << "\n число в ячейке памяти b после программы = " << b;
    return 0;
}
