#include <iostream>

int main() {
    int arr[]{ 1, 2, 3, 4, 5, 6 };
    int a = 3[arr - 1] - arr[3] + (arr - 1)[5];

    std::cout << " " << 1[arr] << std::endl;
    std::cout << " " << 2[arr] << std::endl;
    std::cout << " " << 3[arr] << std::endl;
    std::cout << " " << 4[arr] << std::endl;
    std::cout << " " << 5[arr] << std::endl;
    std::cout << " " << 6[arr] << std::endl;
    std::cout << " " << 7[arr] << std::endl;
    std::cout << " " << 0[arr] << std::endl;
    std::cout << "\n" << 1[arr - 1] << std::endl;
    std::cout << " " << 2[arr - 1] << std::endl;
    std::cout << " " << 3[arr - 1] << std::endl;
    std::cout << " " << 4[arr - 1] << std::endl;
    std::cout << " " << 5[arr - 1] << std::endl;
    std::cout << " " << 6[arr - 1] << std::endl;
    std::cout << " " << 7[arr - 1] << std::endl;
    std::cout << " " << 0[arr - 1] << std::endl;
    std::cout << "\n" << 1[arr + 1] << std::endl;
    std::cout << " " << 2[arr + 1] << std::endl;
    std::cout << " " << 3[arr + 1] << std::endl;
    std::cout << " " << 4[arr + 1] << std::endl;
    std::cout << " " << 5[arr + 1] << std::endl;
    std::cout << " " << 6[arr + 1] << std::endl;
    std::cout << " " << 7[arr + 1] << std::endl;
    std::cout << " " << 0[arr + 1] << std::endl;

    return 0;
}
