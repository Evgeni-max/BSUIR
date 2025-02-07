#include <iostream>
#include <string>
#include <vector>

void main1() {
    std::string str;
    std::cin >> str;

    if (str[0] == 49) {
        size_t length = str.length();
        size_t i = length - 1;

        --str[i];
        while (str[i] < 48) {
            str[i] += 2;
            str[--i] -= 1;
        }
    }

    std::cout << str;
}



void normal_system2(int n, int base, std::string& out) {
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

void sAm2(std::string& strn, std::string& strk, std::string& sum) {
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

void main2() {
    int n, k;
    std::cout << "Enter numbers:\n";

    std::cin >> n >> k;
    std::string strn, strk, sum = "00000000000000000000000000000000";

    normal_system2(n, 2, strn);
    dopolnitelnaia(strn);
    std::cout << "Number 1:\n" << strn << std::endl;

    normal_system2(k, 2, strk);
    dopolnitelnaia(strk);
    std::cout << "Number 2:\n" << strk << std::endl;

    sAm2(strn, strk, sum);
    iz_dop_v_ob(sum);
    std::cout << "Sum:\n" << sum << std::endl;
}

char xz(int sum_i) {
    if (sum_i < 10) sum_i += 48;
    else sum_i += 55;
    return sum_i;
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
void nesAm(std::string&, std::string&, std::string&, int, bool);
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

void main3() {
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
void main4()
{
    int t;
    std::cin >> t;
    std::string str;
    int t4 = t / 1000;

    str.append(t4, 'M');

    int t3 = t % 1000 / 100;
    if (t3 > 0 && t3 < 6) str.append(t3, 'C');
    else if (t3 > 5) {
        str.append(10 - t3, 'C');
        str.push_back('M');
    }

    int t2 = t % 100 / 10;
    if (t2 > 0 && t2 < 4) str.append(t2, 'X');
    else if (t2 == 4) str.append("XL");
    else if (t2 > 4 && t2 < 9) {
        str.push_back('L');
        str.append(t2 - 5, 'X');
    }
    else if (t2 == 9) str.append("XC");

    int t1 = t % 10;
    if (t1 > 0 && t1 < 4) str.append(t1, 'I');
    else if (t1 == 4) str.append("IV");
    else if (t1 > 4 && t1 < 9) {
        str.push_back('V');
        str.append(t1 - 5, 'I');
    }
    else if (t1 == 9) str.append("IX");

    std::cout << str;
}

void main5()
{
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;

        int result = n / 10 + (n % 10 == 9);

        std::cout << result << std::endl;
    }
}

void main6() {
    int n, x;
    std::cin >> n;

    std::cout << "Chose prime number(5, 47, 89):\n";
    std::cin >> x;

metka:
    switch (x) {
    case 5:
        break;
    case 47:
        break;
    case 89:
        break;
    default:
        std::cout << "Its not my number, chose once again:\n";
        std::cin >> x;
        goto metka;
        break;
    }

    int dop = x >> 1;
    ++dop;

    while (n > x) {
        n = (n >> 1) + ((n & 1) ? dop : 0);
    }

    if (n == x || n == 0) std::cout << "Yes";
    else std::cout << "No";
}

void main7() {
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



void normal_system8(int n, int base, std::string& out) {
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

void remade_system8(std::string& out, int base) {
    size_t length = out.length();

    for (int i = length - 1; i > 0; --i) {
        if (out[i] < 49) {
            out[i] += base;
            --out[i - 1];
        }
    }

    if (out[0] == 48) out.erase(0, 1);
}

void checkDay2(int x, std::vector<int>& numbers) {
    int k;
    for (auto i = 0; i < numbers.size(); i++) //O(n)
        if (numbers[i] == x) {
            k = i;
            break;
        }
    int t = 1;
    std::cout << "Умерли во второй день:";
    while (k) { // O(log(n))
        if (k & 1) {
            std::cout << t << " ";
        }
        t++;
        k >>= 1;
    }
    std::cout << "\nНомер бочки\n";
    std::cout << x;
}

void checkDay1(int x, std::vector<int>& numbers) {

    std::vector<int> dead;
    int person1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91,
                     92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112,
                     161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180,
                     181, 182, 183, 184, 201, 202, 203, 204, 205, 206, 207, 208 };

    int person2[] = { 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 81, 82, 83, 84, 85, 86, 87, 88,
                     113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132,
                     133, 134, 135, 136, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 185, 186, 187, 188,
                     189, 190, 191, 192, 193, 194, 195, 196, 201, 202, 203, 204, 205, 206, 209, 210 };

    int person3[] = { 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 89, 90, 91, 92, 93, 94, 95, 96,
                     113, 114, 115, 116, 117, 118, 119, 120, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148,
                     149, 150, 151, 152, 161, 162, 163, 164, 173, 174, 175, 176, 177, 178, 179, 180, 185, 186, 187, 188,
                     189, 190, 191, 192, 197, 198, 199, 200, 201, 202, 203, 204, 207, 208, 209, 210 };

    int person4[] = { 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 97, 98, 99, 100, 101, 102, 103,
                     104, 121, 122, 123, 124, 125, 126, 127, 128, 137, 138, 139, 140, 141, 142, 143, 144, 153, 154, 155,
                     156, 157, 158, 159, 160, 165, 166, 167, 168, 173, 174, 175, 176, 181, 182, 183, 184, 185, 186, 187,
                     188, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 205, 206, 207, 208, 209, 210 };

    int person5[] = { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 105, 106, 107, 108, 109, 110, 111,
                     112, 129, 130, 131, 132, 133, 134, 135, 136, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155,
                     156, 157, 158, 159, 160, 169, 170, 171, 172, 177, 178, 179, 180, 181, 182, 183, 184, 189, 190, 191,
                     192, 193, 194, 195, 196, 197, 198, 199, 200, 203, 204, 205, 206, 207, 208, 209, 210 };

    int all[5][241]{};

    for (int j = 0; j < 80; ++j) { // O(n)
        all[0][person1[j]] = 1;
        all[1][person2[j]] = 1;
        all[2][person3[j]] = 1;
        all[3][person4[j]] = 1;
        all[4][person5[j]] = 1;
    }

    for (int i = 0; i < 5; i++) { // O(n)
        if (all[i][x] == 1) dead.push_back(i);
    }


    for (int i = 1; i < 211; i++) { // O(n^2)
        int sum1 = 0;
        bool s = true;

        for (auto& j : all) {
            if (j[i]) sum1++;
        }

        for (auto j : dead) if (all[j][i] == 0) s = false;

        if (sum1 == dead.size() && s) numbers.push_back(i);
    }

    if (dead.empty()) for (int i = 211; i < 241; i++) numbers.push_back(i);

    std::cout << "Умерли в первый день:";
    for (auto i : dead) std::cout << i + 1 << " "; // O(n)
    std::cout << "\nБочки под подозрением:";
    for (auto i : numbers) std::cout << i << " "; // O(n)
    std::cout << "\n";

    checkDay2(x, numbers);
}

void main9() {
    setlocale(LC_ALL, "Russian");
    int a;
    std::vector<int> numbers;
    std::cout << "Введи номер отравленной бочки\n";
    std::cin >> a;

    checkDay1(a, numbers);

}

void main8() {
    int n;
    std::cin >> n;

    std::string out;

    normal_system8(n, 3, out);
    remade_system8(out, 3);

    std::cout << out;
}