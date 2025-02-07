
#include <iostream>

int main()
{
    int i = 1, sum = 0;
    while (i < 31) {
        if (i % 2) {
            sum += pow((i - i * i), 2);
        }
        else {
            sum += pow((i / 2 + i * i * i), 2);
        }
        i++;
    }
    std::cout << "the sum is equal " << sum;
}
