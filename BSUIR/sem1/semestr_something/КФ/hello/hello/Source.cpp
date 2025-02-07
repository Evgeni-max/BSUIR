#include <iostream>
#include <string>

int main() {
    std::string str;
    getline(std::cin, str);

    size_t length = str.length();
    int numb = 257, mod = 1000000007;
    int* h = new int[length];
    int* xlen = new int[length];

    h[0] = str[0]; xlen[0] = 1;
    for (int i = 1; i < length; ++i) {
        h[i] = (h[i - 1] * numb + str[i]) % mod;
        xlen[i] = (xlen[i - 1] * numb) % mod;
    }


    for (int i = 0; i < length; ++i) {
        std::cout << h[i] << ' ';
    }
    std::cout << std::endl;

    for (int i = 0; i < length; ++i) {
        std::cout << xlen[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << str;
    return 0;
}