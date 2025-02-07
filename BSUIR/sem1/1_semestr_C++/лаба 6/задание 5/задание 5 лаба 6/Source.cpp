#include <iostream>
#include <cstring>


long long bin_pow(unsigned long long, unsigned long long, unsigned long long);

int main() {
    unsigned long long t, L, m;
    std::string s1, s2;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> L >> m >> s1 >> s2;

        size_t s1l = s1.length();
        size_t s2l = s2.length();
                                             
        long long variant = L - s1l - s2l;   
        unsigned long long result;           
//////////////////
        if (variant < 0) {
            if (s1l > L || s2l > L) {
                result = 0;                
            }
            else {
                variant = -variant;
                bool if1 = s1.compare(s1l - variant, variant, s2, 0, variant) == 0;
                bool if2 = s2.compare(s2l - variant, variant, s1, 0, variant) == 0;
                result = (if1 + if2) % m;
            }
        }
        else {
            if (variant == 0) result = 2;
            else {
                unsigned long long allvariant = bin_pow(26, variant, m);
                result = allvariant * 2;
            }
        }
///////////////////
        if (s1 == s2) {
            result /= 2;
            result %= m;
        }           

////////////////////
        int minresult = 0;
        if (s1l > s2l) {
            if (s1.compare(0, s2l, s2) == 0 && s1.compare(s1l - s2l, s2l, s2) == 0) {
                
                int dif = L - 2 * s1l;

                if (dif > 0) {
                    minresult = bin_pow(26, dif, m);
                }
                else if (dif == 0) minresult = 1;
                else {
                    dif = -dif;
                    if (s1.compare(0, dif, s1, s1l - dif, dif) == 0) {
                        minresult = 1;
                    }
                    else minresult = 0;
                }
            }
        }
        else if (s1l < s2l) {
            if (s2.compare(0, s1l, s1) == 0 && s2.compare(s2l - s1l, s1l, s1) == 0) {
                int dif = L - 2 * s2l;

                if (dif > 0) {
                    minresult = bin_pow(26, dif, m);
                }
                else if (dif == 0) minresult = 1;
                else {
                    dif = -dif;
                    if (s2.compare(0, dif, s2, s2l - dif, dif) == 0) {
                        minresult = 1;
                    }
                    else minresult = 0;
                }
            }

        }
////////////////////////        
        std::cout << (result - minresult) % m << std::endl;
    }


    return 0;
}

long long bin_pow(unsigned long long base, unsigned long long p, unsigned long long MOD) {
    if (p == 1) {
        return base;    //Выход из рекурсии.
    }

    if (p % 2 == 0) {
        unsigned long long t = bin_pow(base, p / 2, MOD);
        return t * t % MOD;
    }
    else {
        return bin_pow(base, p - 1, MOD) * base % MOD;
    }
}
