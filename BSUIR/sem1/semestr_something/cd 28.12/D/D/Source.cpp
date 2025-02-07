#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

int main()
{
    int t;
    std::cin >> t;

    for (int h = 0; h < t; ++h) {
        int n, q;
        std::cin >> n;
        std::vector<int> a(n), ic;

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::cin >> q;
        std::vector<std::pair<int, int>> qrr(q), no;
        for (int i = 0; i < q; ++i) {
            std::cin >> qrr[i].first;
            std::cin >> qrr[i].second;
        }

        int m = 0;
        int pred_in = -1;
        bool is = 0;
        int pair_in = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] == a[i - 1]) {
                if (!is) {
                    pred_in = i - 1;
                    is = 1;
                }
            }
            else {
                if (is) {
                    no.push_back(std::pair<int, int>(pred_in + 1, i));
                    is = 0;
                }
            }
        }
        if (is) {
            no.push_back(std::pair<int, int>(pred_in + 1, n));
            is = 0;
        }

        for (int i = 0; i < q; ++i) {
            if (no.size() > 0) {
            int m = 0;
            while ((m < no.size()) && (no[m].first < qrr[i].first)) {
                ++m;
            }
            if (m != 0)
                --m;
            if (no[m].second >= qrr[i].second) {
                std::cout << -1 << ' ' << -1 << std::endl;
            }
            else
                std::cout << qrr[i].first << ' ' << no[m].second + 1 << std::endl;
            }
            else {
                std::cout << qrr[i].first << ' ' << qrr[i].second << std::endl;
            }
            
        }
    }
}