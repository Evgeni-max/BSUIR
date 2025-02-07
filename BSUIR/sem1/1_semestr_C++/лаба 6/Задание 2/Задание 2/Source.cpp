
#include <iostream>
#include <string>

int main() {
    setlocale(LC_ALL, "russian");

    char* a = new char[80];
    int q = 0;

    std::cout << "¬ведите текст:" << std::endl;
    for (int i = 0; i < 80; i++) {
        a[i] = getchar();
        if (a[i] == '\n') {
            a[i] = '\0';
            break;
        }
        q++;
    }



    char* b = new char[80];
    int w = 0;

    std::cout << "¬ведите подстроку, которую хотите вставить в текст:";



    for (int i = 0; i < 80; i++) {
        b[i] = getchar();
        if (b[i] == '\n') {
            b[i] = '\0';
            break;
        }
    }


    std::cout << "¬ведите длину слова:";
    int dlina;
    std::cin >> dlina;

    int d = 0;
    std::string str1 = a;
    std::string str2 = b;

    for (int i = 0; i < q; i++) {
        if (str1[i] != ' ') {
            d++;
        }
        if (str1[i] == ' ') {
            if (d == dlina) {
                str1.erase(i - d, d);
                str1.insert(i - d, str2);
            }
            d = 0;
        }

    }
    std::cout << str1;

    return 0;
}