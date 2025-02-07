
#include <iostream>
#include <climits>

int main()
{
    setlocale(LC_ALL, "Russian");

    int a, b;
    std::cin >> a >> b;

    if (a < INT_MIN || b < INT_MIN || a > INT_MAX || b > INT_MAX) {
        std::cout << "возникло целочисленное переполнение ячеек";
    } else {
        std::cout << " число в ячейке памяти а до программы = " << a << "\n число в ячейке памяти b до программы = " << b;

        a = a + b;
        b = a - b;
        a = a - b;

        std::cout << "\n число в ячейке памяти а после программы = " << a << "\n число в ячейке памяти b после программы = " << b;
    }

    
  
    return 0;
}


