#include <iostream>
#include <string>

int main() {
    int n = 0;
    std::cin >> n;

    int* a = new int[14];
    
    a[1] = 1;
    a[2] = 10;
    a[3] = 11;
    a[4] = 100;
    a[5] = 101;
    a[6] = 110;
    a[7] = 111;
    a[8] = 1000;
    a[9] = 1001;
    a[10] = 1100;
    a[11] = 1101;
    
    if (n < 12) std::cout << a[n];
    else {
        long long x = (n - 12) / 8 + 5;
        long long y = (n - 12) % 8;

        std::string result = "1";
        result.append(x - 1, '0');

        switch (y) {
        case 0:
            break;
        case 1:
            result[x - 1] = '1';
            break;
        case 2:
            if (x % 2 == 1) result[2] = '1';
            else if (x % 4 == 0) result[3] = '1';
            else {
                result[2] = '1';
                result[3] = '1';
            }
            break;
        case 3:
            if (x % 2 == 1) result[2] = '1';
            else if (x % 4 == 0) result[3] = '1';
            else {
                result[2] = '1';
                result[3] = '1';
            }

            result[x - 1] = '1';
            break;
        case 4:
            result[1] = '1';
            break;
        case 5:
            result[1] = '1';

            result[x - 1] = '1';
            break;
        case 6:
            result[1] = '1';

            if (x % 2 == 1) result[2] = '1';
            else if (x % 4 == 0) result[3] = '1';
            else {
                result[2] = '1';
                result[3] = '1';
            }
            break;
        case 7:
            result[1] = '1';

            if (x % 2 == 1) result[2] = '1';
            else if (x % 4 == 0) result[3] = '1';
            else {
                result[2] = '1';
                result[3] = '1';
            }

            result[x - 1] = '1';
            break;
        default:
            break;
        }

        std::cout << result;
    }
}