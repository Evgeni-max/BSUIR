#include <iostream>


bool proiz(int n) {
    int mul;
    if (n == 1) return 1;

    for (mul = 1; n; n /= 10 )
        if(n % 2 == 0) return false;

    return true;
}
int main(){

    for(long long i = 201; i < 10000000; i += 201) {
        if(proiz(i) == 1) std::cout << i << '\n';
    }
    return 0;
}
