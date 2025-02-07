//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <set>
//#include <cmath>
//
//int if_find(std::vector<int>& a, int beg, int end, int x) {
//    if (beg > end) {
//        return -1;
//    }
//    else if (beg == end) {
//        if (a[beg] == x) {
//            return beg;
//        }
//        else 
//           return -1;
//    }
//
//    if (a[(end - beg) / 2] > x) {
//        return if_find(a, beg, (end - beg) / 2 - 1, x);
//    }
//    else if (a[(end - beg) / 2] < x) {
//        return if_find(a, (end - beg) / 2 + 1, end, x);
//    }
//    else
//        return true;
//}
//
//int main()
//{
//    int t;
//    std::cin >> t;
//
//    for (int h = 0; h < t; ++h) {
//        int n;
//        std::cin >> n;
//        std::vector<int> a(n);
//        std::set<int> numb;
//
//        for (int i = 0; i < n; ++i) {
//            std::cin >> a[i];
//        }
//        for (int i = 2; i < n + 1; ++i) {
//            numb.insert(i);
//        }
//
//        sort(a.begin(), a.end());
//        
//        long long x = a[n - 1] + 1;
//        int count = 0;
//        for (int i = n - 2; i > -1; --i) {
//            if (if_find(a, 0, n - 1, x - a[i]) != -1) {
//                numb.erase(x - a[i]);
//                ++count;
//            }
//        }
//
//        std::cout << count << std::endl;
//    }
//}

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>

int main()
{
    int t;
    std::cin >> t;

    for (int h = 0; h < t; ++h) {
        long long n, x, y;
        long long total = 0, ar2 = 1 ;
        std::cin >> n >> x >> y;
        std::vector<long long> a(n), copy(n);
        std::vector < std::vector <long long>> arry(y);

        for (long long i = 0; i < n; ++i) {
            std::cin >> a[i];
            copy[i] = a[i] % y;
        }

        for (long long i = 0; i < n; ++i) {
            arry[copy[i]].push_back(i);
        }

        for (long long h = 0; h < y; ++h) {
            long long siz = arry[h].size();

            for (long long i = 0; i < siz; ++i) {
                for (long long j = i + 1; j < siz; ++j) {
                    if ((a[arry[h][i]] + a[arry[h][j]]) % x == 0)
                        ++total;
                }
            }
        }

        std::cout << total << std::endl;
       
    }
}