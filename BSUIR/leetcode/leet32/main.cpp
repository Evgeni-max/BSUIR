#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0;
        stack<int> stc;
        stc.push(-1);

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stc.push(i);
            }
            else {
                if (stc.size() == 1) {
                    stc.top() = i;
                }
                else {
                    stc.pop();
                    if (max < i - stc.top()) max = i - stc.top();
                }
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    string k = "()(((())(()())()())()()()()(((()))()())";
    cout << s.longestValidParentheses(k);
}