#include <iostream>
#include <string>

void normal_system(int, int, std::string&);
void sAm(std::string&, std::string&, std::string&, int, bool);
char xz(int);
void nesAm(std::string&, std::string&, std::string&, int, bool);

int main() {
    int n, k, base;

    std::cout << "Enter numbers:\n";
    std::cin >> n >> k;
    std::cout << "Enter base:\n";
    std::cin >> base;

    std::string strn, strk, sum = "00000000000000000000000000000000";

    bool znak_chisla = abs(n) > abs(k);

    normal_system(n, base, strn);
    std::cout << "Number 1:\n" << strn << std::endl;

    normal_system(k, base, strk);
    std::cout << "Number 2:\n" << strk << std::endl;

    sAm(strn, strk, sum, base, znak_chisla);
    std::cout << "Result:\n" << sum;
    /*
    sAm(strn, strk, sum);
    iz_dop_v_ob(sum);
    std::cout << "Sum:\n" << sum << std::endl;*/
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
    for (; count < 31; ++count) {
        arrbase[count] = max;
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

            if (elcount < 10) out.push_back(elcount + 48);
            else out.push_back(elcount + 55);
        }
    }
}

void sAm(std::string& strn, std::string& strk, std::string& sum, int base, bool znak_chisla) {
    if (strn[0] != strk[0]) {
        if (strn[0] == 49) {
            strn[0] = 48;
            nesAm(strk, strn, sum, base, znak_chisla - 1);
            return;
        }
        else {
            strk[0] = 48;
            nesAm(strn, strk, sum, base, znak_chisla);
            return;
        }
    }

    bool perevod = 0;
    int sum_i = 0;

    for (int i = 31; i > 0; --i) {
        if (strn[i] < 58 && strk[i] < 58) {
            sum_i = strn[i] + strk[i] - 96 + perevod;
            if (sum_i >= base) {
                perevod = 1;
                sum_i -= base;
                sum[i] = xz(sum_i);
                sum_i = 0;
            }
            else {
                perevod = 0;
                sum[i] = xz(sum_i);
                sum_i = 0;
            }
        }
        else if (strn[i] > 58 && strk[i] > 58) {
            sum_i = strn[i] + strk[i] - 110 + perevod;
            if (sum_i >= base) {
                perevod = 1;
                sum_i -= base;
                sum[i] = xz(sum_i);
                sum_i = 0;
            }
            else {
                perevod = 0;
                sum[i] = xz(sum_i);
                sum_i = 0;
            }
        }
        else {
            sum_i = strn[i] + strk[i] - 103 + perevod;
            if (sum_i >= base) {
                perevod = 1;
                sum_i -= base;
                sum[i] = xz(sum_i);
                sum_i = 0;
            }
            else {
                perevod = 0;
                sum[i] = xz(sum_i);
                sum_i = 0;
            }
        }
    }

    sum[0] = strn[0];
}

char xz(int sum_i) {
    if (sum_i < 10) sum_i += 48;
    else sum_i += 55;
    return sum_i;
}

void nesAm(std::string& strn, std::string& strk, std::string& sum, int base, bool znak_chisla) {
    if (strn[0] != strk[0]) {
        if (strn[0] == 49) {
            strk[0] = 49;
            sAm(strk, strn, sum, base, znak_chisla);
            return;
        }
        else {
            strk[0] = 48;
            sAm(strn, strk, sum, base, znak_chisla);
            return;
        }
    }
    else if (strn[0] == 49) {
        strn[0] = 48;
        strk[0] = 48;
        nesAm(strk, strn, sum, base, znak_chisla - 1);
        return;
    }

    if (znak_chisla == 0) {
        sum[0] = 49;
        nesAm(strk, strn, sum, base, znak_chisla - 1);
        return;
    }

    bool perevod = 0;
    int sum_i = 0;

    for (int i = 31; i > 0; --i) {
        if (strn[i] < 58 && strk[i] < 58) {
            sum_i = strn[i] - strk[i] - perevod;
            if (sum_i < 0) {
                perevod = 1;
                sum_i += base;
                sum[i] = xz(sum_i);
                sum_i = 0;
            }
            else {
                perevod = 0;
                sum[i] = xz(sum_i);
                sum_i = 0;
            }
        }
        else if (strn[i] > 58 && strk[i] > 58) {
            sum_i = strn[i] - strk[i] - perevod;
            if (sum_i < 0) {
                perevod = 1;
                sum_i += base;
                sum[i] = xz(sum_i);
                sum_i = 0;
            }
            else {
                perevod = 0;
                sum[i] = xz(sum_i);
                sum_i = 0;
            }
        }
        else {
            if (strn[i] > 58) {
                sum_i = strn[i] - strk[i] - 7 - perevod;
                if (sum_i < 0) {
                    perevod = 1;
                    sum_i += base;
                    sum[i] = xz(sum_i);
                    sum_i = 0;
                }
                else {
                    perevod = 0;
                    sum[i] = xz(sum_i);
                    sum_i = 0;
                }
            }
            else {
                sum_i = strn[i] - strk[i] + 7 - perevod;
                if (sum_i < 0) {
                    perevod = 1;
                    sum_i += base;
                    sum[i] = xz(sum_i);
                    sum_i = 0;
                }
                else {
                    perevod = 0;
                    sum[i] = xz(sum_i);
                    sum_i = 0;
                }
            }
        }
    }

}