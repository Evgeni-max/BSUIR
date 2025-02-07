#include <iostream>
#include <string>



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



int main() {
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
}