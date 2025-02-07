#include <iostream>

int main() {
    long long a, b, t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::cin >> a >> b;

        if ((a + b) % 2)
            std::cout << "Alice" << std::endl;
        else
            std::cout << "Bob" << std::endl;
    }
}