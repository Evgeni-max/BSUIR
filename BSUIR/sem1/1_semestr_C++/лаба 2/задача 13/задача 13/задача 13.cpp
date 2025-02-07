#include <string>
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int k, sw;
    std::string okonchanie;
    std::cin >> k;

    if (k % 100 / 10 == 1) {
        sw = 3;
    }
    else if (k % 10 == 1) {
        sw = 1;
    }
    else if (k % 10 > 1 && k % 10 < 5) {
        sw = 2;
    }
    else sw = 3;

    switch (sw) {
    case 1:
        okonchanie = "";
        break;
    case 2:
        okonchanie = "а";
        break;
    default:
        okonchanie = "ов";
        break;
    }
    std::cout << "Мы нашли " << k << " гриб" << okonchanie << " в лесу";
}
 