#include <iostream>
#include <string>

int main()
{
    int t;
    std::cin >> t;
    std::string str;
    int t4 = t / 1000;

    str.append(t4, 'M');

    int t3 = t % 1000 / 100;
    if (t3 > 0 && t3 < 6) str.append(t3, 'C');
    else if (t3 > 5) {
        str.append(10 - t3, 'C');
        str.push_back('M');
    }

    int t2 = t % 100 / 10;
    if (t2 > 0 && t2 < 4) str.append(t2, 'X');
    else if (t2 == 4) str.append("XL");
    else if (t2 > 4 && t2 < 9) {
        str.push_back('L');
        str.append(t2 - 5, 'X');
    }
    else if (t2 == 9) str.append("XC");

    int t1 = t % 10;
    if (t1 > 0 && t1 < 4) str.append(t1, 'I');
    else if (t1 == 4) str.append("IV");
    else if (t1 > 4 && t1 < 9) {
        str.push_back('V');
        str.append(t1 - 5, 'I');
    }
    else if (t1 == 9) str.append("IX");

    std::cout << str;
}

