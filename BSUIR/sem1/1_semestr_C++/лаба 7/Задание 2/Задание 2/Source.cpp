#include <iostream>
#include <string>

void normal_system(int, int, std::string&);
void dopolnitelnaia(std::string&);
void sAm(std::string&, std::string&, std::string&);
void iz_dop_v_ob(std::string&);

int main() {
	int n, k;
    std::cout << "Enter numbers:\n";

	std::cin >> n >> k;
    std::string strn, strk, sum = "00000000000000000000000000000000";

    normal_system(n, 2, strn);
    dopolnitelnaia(strn);
    std::cout << "Number 1:\n" << strn << std::endl;

    normal_system(k, 2, strk);
    dopolnitelnaia(strk);
    std::cout << "Number 2:\n" << strk << std::endl;

    sAm(strn, strk, sum);
    iz_dop_v_ob(sum);
    std::cout << "Sum:\n" << sum << std::endl;
}

void normal_system(int n, int base, std::string& out) {
    long long* arrbase = new long long[70];
    long long max = INT_MAX;
    long long bbase = 1, count = 0;

    if (n < 0) {
        out.push_back('1');
        n = -n;
    }
    else out.push_back('0');

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
            //if (start == 1) 
            out.push_back(48);
            --count;
            continue;
        }
        else {
            //start = 1;
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

void dopolnitelnaia(std::string& str) {
    if (str[0] == 49) {
        size_t length = str.length();
        //в обратный
        for (int i = 1; i < length; ++i) {
            if (str[i] == 49) --str[i];
            else ++str[i];
        }
        
        size_t i = length - 1;
        //в дополнительный
        ++str[i];
        while (str[i] > 49) {
            str[i] -= 2;
            str[--i] += 1;
        }
    }
}

void sAm(std::string& strn, std::string& strk, std::string& sum) {
    bool perevod = 0;

    for (int i = 31; i >= 0; --i) {
        if (strn[i] == strk[i]) {
            if (strn[i] == 49) {
                sum[i] = perevod + 48;
                perevod = 1;
            }
            else {
                sum[i] = perevod + 48;
                perevod = 0;
            }
        }
        else {
            if (perevod) {
                sum[i] = 48;
                perevod = 1;
            }
            else {
                sum[i] = 49;
                perevod = 0;
            }
        }
    }
}

void iz_dop_v_ob(std::string& str) {
    if (str[0] == 49) {
        size_t length = str.length();
        size_t i = length - 1;

        --str[i];
        while (str[i] < 48) {
            str[i] += 2;
            str[--i] -= 1;
        }

        for (size_t i = 1; i < length; i++) {
            if (str[i] == 49) str[i] = 48;
            else str[i] = 49;
        }
    }
}