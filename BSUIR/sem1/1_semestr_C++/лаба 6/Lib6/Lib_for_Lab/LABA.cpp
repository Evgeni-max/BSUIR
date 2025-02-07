#include <string>
#include <iostream>

int main1()
{
    char ch;
    const int sizeofchararray = 100; 
    int size = sizeofchararray;
    char* nums = new char[size];

    int count = 0;
    // check input
    std::cout << "Кто введет строку длиной больше 5 тот конченный пидорас";
    while ((ch = getchar()) != '\n') {
        if (ch == ' ') continue;
        else {  
           nums[count] = ch;
           count++;
              if (count >= size) {
                  size += sizeofchararray;
                  nums = (char*)realloc(nums, size * sizeof(char));
              }
        }
       
    }
    nums[count] = '\0';

    char today = nums[0];
    int todaycount = 1, mincount = count;
    for (int i = 1; i < count; i++) {

        if (nums[i] == today) {
            todaycount++;
        }
        else {
            today = nums[i];
            if (todaycount < mincount) mincount = todaycount;
            todaycount = 1;
        }
    }
    if (todaycount < mincount) mincount = todaycount;


    std::cout << "Min groop: " << mincount;

    free(nums);
    nums = nullptr;
    return 0;
}




int main2() {
    setlocale(LC_ALL, "russian");

    char* a = new char[80];
    int q = 0;

    std::cout << "Введите текст:" << std::endl;
    for (int i = 0; i < 80; i++) {
        a[i] = getchar();
        if (a[i] == '\n') {
            a[i] = '\0';
            break;
        }
        q++;
    }

    char* b = new char[80];
    int w = 0;

    std::cout << "Введите подстроку, которую хотите вставить в текст:";

    for (int i = 0; i < 80; i++) {
        b[i] = getchar();
        if (b[i] == '\n') {
            b[i] = '\0';
            break;
        }
    }

    std::cout << "Введите длину слова:";
    int dlina;
    std::cin >> dlina;

    int d = 0;
    std::string str1 = a;
    std::string str2 = b;

    for (int i = 0; i < q; i++) {
        if (str1[i] != ' ') {
            d++;
        }
        if (str1[i] == ' ') {
            if (d == dlina) {
                str1.erase(i - d, d);
                str1.insert(i - d, str2);
            }
            d = 0;
        }

    }
    std::cout << str1;

    free(a);
    a = nullptr;
    return 0;
}





void zamena(int number, char* result) {
    int i = 0;
    // Обрабатываем каждую цифру числа, начиная с конца
    while (number > 0) {
        int s = number % 10;
        result[i++] = 48 + s;
        number /= 10;
    }

    // Переворачиваем значения
    int left = 0, right = i - 1;
    while (left < right) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
        left++; right--;
    }

    result[i] = '\0';
}


int main3() {
    const int arraySize = 3;
    char str[80];
    int q = 0;

    for (int i = 0; i < 100; i++) {
        str[i] = getchar();
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        q++;
    }

    char t[200];
    int e = 0;
    for (int i = 0; i < 200; i++) { t[i] = '\0'; }
    for (int i = 0, j = 0; i < q; i++, j++) {
        e = 0;
        if (str[i] == str[i + 1]) {
            while (str[i] == str[i + 1]) {
                i++;
                e++;
            }

            t[j] = '2';
            t[++j] = '5';
            t[++j] = '5';

            char temp[4];
            int h = 0;

            zamena(int(str[i]), temp);
            while (temp[h] != '\0') {
                t[++j] = temp[h++];

            }

            h = 0;

            zamena(e + 1, temp);
            while (temp[h] != '\0') {
                t[++j] = temp[h++];
            }
        }
        else {
            t[j] = str[i];
        }
    }
    std::cout << t;


    return 0;
}





void bigbukovki(std::string& str) {
    size_t lenght = str.length();
    std::string BIG = "CQWX";

    for (unsigned i{}; i < lenght; )
    {
        // получаем индекс
        size_t position = str.find_first_of(BIG, i);
        // если не найдено ни одного вхождения с индекса i, выходим из цикла
        if (position == std::string::npos) break;

        str.erase(position, 1);
        --lenght;
        // переходим к следующему индексу после position
        i = position;
    }
}

void bukovki(std::string& str) {
    size_t lenght = str.length();
    std::string tests = "eiy";
    size_t lenght1 = lenght - 1;

    for (int i = 0; i < lenght1; ++i) {
        if (str[i] == 'c') {
            if (tests.find(str[i + 1]) != std::string::npos) str[i] = 's';
            else str[i] = 'k';
        }
        if (str[i] == 'q') {
            if (str[i + 1] == 'u') str[i + 1] = 'v';
            str[i] = 'k';
        }
        if (str[i] == 'x') str.replace(i, 1, "ks");
        if (str[i] == 'w') str[i] = 'v';
    }
}

void remaining(std::string& str, std::string findstr, std::string newstr) {
    size_t lenght = str.length();
    size_t lenghtfind = findstr.length();
    size_t lenghtnew = newstr.length();

    for (unsigned i{}; i <= lenght - lenghtfind; )
    {
        // получаем индекс
        size_t position = str.find(findstr, i);
        // если не найдено ни одного вхождения с индекса i, выходим из цикла
        if (position == std::string::npos) break;

        str.replace(position, lenghtfind, newstr);
        lenght -= lenghtfind - lenghtnew;
        // переходим к следующему индексу после position
        i = position + 1;
    }
}

void doblesogl(std::string& str) {
    size_t lenght = str.length();
    std::string soglasnie = "bcdfghjklmnpqrstvwxz";
    size_t lenght1 = lenght - 1;

    for (unsigned i{}; i < lenght1; )
    {
        // получаем индекс
        size_t position = str.find_first_of(soglasnie, i);
        // если не найдено ни одного вхождения с индекса i, выходим из цикла
        if (position == std::string::npos) break;

        if (str[position + 1] == str[position]) {
            str.erase(position, 1);
            --lenght1;
            i = position;
        }
        else {
            i = position + 1;
        }
        // переходим к следующему индексу после position
    }
}


int main4() {
    std::string str;

    int i = 0;
    char c;
    while ((c = getchar()) != EOF) {
        str.push_back(c);
        ++i;
    }

    bigbukovki(str);
    bukovki(str);

    remaining(str, "you", "u");
    remaining(str, "You", "U");
    remaining(str, "oo", "u");
    remaining(str, "Oo", "U");
    remaining(str, "ee", "i");
    remaining(str, "Ee", "I");
    remaining(str, "Th", "Z");
    remaining(str, "th", "z");
    remaining(str, "ph", "f");
    remaining(str, "Ph", "F");


    doblesogl(str);
    std::cout << str;
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



int main5() {
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







long long factorial(int n) {
    if (n == 1) return 1;
    else return n * factorial(n - 1);
}


void count_different_numbers(std::string& str, long long* arr, int numb) {
    size_t length = str.length();
    unsigned count = 1;       // количество вхождений


    for (int i = 1; i < length; )
    {
        // получаем индекс
        size_t position = str.find(str[0], i);
        // если не найдено ни одного вхождения с индекса i, выходим из цикла
        if (position == std::string::npos) break;
        // если же вхождение найдено, увеличиваем счетчик вхождений
        ++count;
        str.erase(position, 1);
        --length;
        // переходим к следующему индексу: position
        i = position;
    }
    str.erase(0, 1);
    --length;


    arr[numb] = factorial(count);


    if (length < 2) return;
    else count_different_numbers(str, arr, ++numb);
}



int main6() {
    std::string str;
    std::cin >> str;
    long long* arr = new long long[14];

    long long nfactor = factorial(str.length());

    for (int i = 0; i < 14; ++i) {
        arr[i] = 0;
    }

    count_different_numbers(str, arr, 0);
    for (int i = 0; i < 14, arr[i] != 0; ++i) {
        nfactor /= arr[i];
    }

    std::cout << nfactor;
    
    return 0;
}





bool check_polindrom(std::string& str) {
    size_t lenght = str.length();
    size_t lenght1 = lenght - 1;
    size_t halflenght = lenght / 2;
    for (int i = 0; i < halflenght; ++i) {
        if (str[i] != str[lenght1 - i]) {
            return 0;
        }
    }
    return 1;
}

bool check_string_of_equal_numbers(std::string& str) {
    size_t lenght1 = str.length() - 1;
    for (int i = 0; i < lenght1; ++i) {
        if (str[i] != str[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int main7() {
    std::string str;
    std::cout << "Give me str: ";
    std::cin >> str;
    size_t lenght = str.length();

    if (check_polindrom(str)) {
        if (check_string_of_equal_numbers(str)) std::cout << -1;
        else std::cout << lenght - 1;
    }
    else std::cout << lenght;

    return 0;
}



int main8() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::string str1, str2, strpolindrom;
        std::cin >> str1 >> str2;
        strpolindrom = str1;

        size_t strlen1 = str1.length();
        size_t strlen2 = str2.length();


        for (int i = strlen1 - 2; i >= 0; i--) {
            strpolindrom.push_back(str1[i]);
        }
        std::cout << strpolindrom << std::endl;
        size_t strlenpol = strpolindrom.length();



        bool chek = 0;
        if (str1 == str2) chek = 1;

        while (strlenpol > 2) {
            if (strpolindrom.find(str2) != std::string::npos) {
                chek = 1;
                std::cout << strpolindrom << std::endl;
                break;
            }
            else {
                strpolindrom.erase(strlenpol / 2, 2);
                strlenpol -= 2;
                std::cout << strpolindrom << std::endl;
            }
        }


        if (chek) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}