#include <iostream>
#include <cmath>

void normal_system(int, int, std::string&);
void remade_system(std::string&, int);

int main() {
    int n;
    std::cin >> n;

    std::string out;

    normal_system(n, 3, out);
    remade_system(out, 3);

    std::cout << out;
    return 0;
}

void normal_system(int n, int base, std::string& out) {
    long long* arrbase = new long long[70];
    long long max = INT_MAX;
    long long bbase = 1, count = 0;

    while (max > bbase) {
        arrbase[count] = bbase;
        bbase *= base;
        ++count;
    }
    --count;

    int  elcount = 0;
    long long powe;
    bool start = 0;

    while (count > -1) {
        if (n < arrbase[count]) {
            if (start == 1) out.push_back(48);
            --count;
            continue;
        }
        else {
            start = 1;
            elcount = 0;
            while (n >= arrbase[count]) {
                n -= arrbase[count];
                elcount++;
            }
            --count;
            out.push_back(elcount + 48);
        }
    }
}

void remade_system(std::string& out, int base) {
    size_t length = out.length();

    for (int i = length - 1; i > 0; --i) {
        if (out[i] < 49) {
            out[i] += base;
            --out[i - 1];
        }
    }

    if (out[0] == 48) out.erase(0, 1);
}