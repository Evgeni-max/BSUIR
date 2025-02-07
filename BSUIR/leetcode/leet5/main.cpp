#include <vector>
#include <algorithm>
#include "iostream"

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        size_t stringSize = s.size();
        if (stringSize < 2) return s;
        if (stringSize == 2) {
            if (s[0] == s[1]) return s;
            else return s.substr(0, 1);
        }
        vector<int> a;
        int count = 1;
        for (int i = 1; i < stringSize - 1; ++i) {
            if (s[i - 1] == s[i + 1]) {
                a.push_back(i);
            }
        }
        int last_i = 0;

        if (a.size() != 0) {
            while(a.size() != 0) {
                last_i = a[0];
                ++count;
                for (int i = a.size() - 1; i > -1; --i) {
                    if (a[i] - count < 0 || a[i] + count > stringSize - 1 || s[a[i] - count] != s[a[i] + count]) {
                        a.erase(a.begin() + i);
                    }
                }
            }
            --count;
        }
        else {
            count = 0;
        }

        vector<int> a2;
        int count2 = 1;
        for (int i = 0; i < stringSize - 1; ++i) {
            if (s[i] == s[i + 1]) {
                a2.push_back(i);
            }
        }
        int last_i2 = 0;

        if (a2.size() != 0) {
            while(a2.size() != 0) {
                last_i2 = a2[0];
                ++count2;
                for (int i = a2.size() - 1; i > -1; --i) {
                    if (a2[i] + 1 - count2 < 0 || a2[i] + count2 > stringSize - 1 || s[a2[i] + 1 - count2] != s[a2[i] + count2]) {
                        a2.erase(a2.begin() + i);
                    }
                }
            }
            --count2;
        }
        else {
            count2 = 0;
        }

        if (count * 2 + 1 > count2 * 2) {
            return s.substr(last_i - count, count * 2 + 1);
        }
        else return s.substr(last_i2 + 1 - count2, count2 * 2);
    }
};

int main() {
    Solution s;
    string str {"cbbd"};
    cout << s.longestPalindrome(str);
}