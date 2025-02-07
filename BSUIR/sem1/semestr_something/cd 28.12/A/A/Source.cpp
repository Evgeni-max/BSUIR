#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

int main()
{
    int t;
    std::cin >> t;

    for (int h = 0; h < t; ++h) {
        int n1, n2, k;
        std::cin >> n1 >> n2 >> k;
        std::vector<int> a1(n1), a2(n2);
        std::set<int> sa1, sa2, saf;

        for (int i = 0; i < n1; ++i) {
            std::cin >> a1[i];
        }
        for (int i = 0; i < n2; ++i) {
            std::cin >> a2[i];
        }

        std::sort(begin(a1), end(a1));
        std::sort(begin(a2), end(a2));

        int m = 0;
        while ((m < n1) && (a1[m] <= k)) {
            sa1.insert(a1[m]);
            ++m;
        }

        m = 0;
        while ((m < n2) && (a2[m] <= k)) {
            sa2.insert(a2[m]);
            ++m;
        }

        for (int n : sa1) {
            saf.insert(n);
        }
        for (int n : sa2) {
            saf.insert(n);
        }

        if ((sa1.size() >= k / 2) && (sa2.size() >= k / 2) && (saf.size() >= k))
            std::cout << "YES" << std::endl;
        else 
            std::cout << "NO" << std::endl;
    }
}



//int main()
//{
//    int t;
//    std::cin >> t;
//
//    for (int h = 0; h < t; ++h) {
//        int n1, n2, k;
//        std::cin >> n1 >> n2 >> k;
//        std::vector<int> a1(n1), a2(n2);
//        std::set<int> sa1, sa2, saf;
//
//        for (int i = 0; i < n1; ++i) {
//            std::cin >> a1[i];
//        }
//        for (int i = 0; i < n2; ++i) {
//            std::cin >> a2[i];
//        }
//
//        std::sort(begin(a1), end(a1));
//        std::sort(begin(a2), end(a2));
//
//        int m = 0;
//        while ((m < n1) && (a1[m] <= k)) {
//            sa1.insert(a1[m]);
//            ++m;
//        }
//
//        m = 0;
//        while ((m < n2) && (a2[m] <= k)) {
//            sa2.insert(a2[m]);
//            ++m;
//        }
//
//        for (int n : sa1) {
//            saf.insert(n);
//        }
//        for (int n : sa2) {
//            saf.insert(n);
//        }
//
//        if ((sa1.size() >= k / 2) && (sa2.size() >= k / 2) && (saf.size() >= k))
//            std::cout << "YES" << std::endl;
//        else 
//            std::cout << "NO" << std::endl;
//    }
//}