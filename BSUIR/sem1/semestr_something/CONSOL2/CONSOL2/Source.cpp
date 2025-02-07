#include <iostream>
#include <climits>
#include <iostream>

struct at {
    int a1 : 1;
    bool a2 : 1;
    bool a3 : 1;
    bool a4 : 1;
    bool a5 : 1;
    bool a6 : 1;
    bool a7 : 1;
    int a8 : 1;
};

union h{
    at d;
    char k;
};

int main() {
    h* arr = new h[6];
    
    const char* a = "abcdef";

    for (int i = 0; i < 6; ++i) {
        arr[i].k = a[i];
    }

    for (int i = 0; i < 6; ++i) {
        std::cout << arr[i].d.a8 << ' ';
        std::cout << arr[i].d.a7 << ' ';
        std::cout << arr[i].d.a6 << ' ';
        std::cout << arr[i].d.a5 << ' ';
        std::cout << arr[i].d.a4 << ' ';
        std::cout << arr[i].d.a3 << ' ';
        std::cout << arr[i].d.a2 << ' ';
        std::cout << arr[i].d.a1 << ' ';
        std::cout << std::endl;
    }
    std::cout << sizeof(at);
}