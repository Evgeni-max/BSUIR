#include <iostream>

using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        int previous = 0;
        for(int i = 0; i < t.size(); ++i) {
            if (t[i] == s[previous]) {
                ++previous;
                if (previous == s.size()) return true;
            }
        }
        return false;
    }
};
