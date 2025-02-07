#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() < 2) return false;

        stack<char> stc;
        stc.push(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stc.push(s[i]);
            }
            else {
                if (s[i] == ')') {
                    if (!stc.empty() && stc.top() == '(') stc.pop();
                    else return false;
                }
                else if (!stc.empty() && s[i] == '}') {
                    if (stc.top() == '{') stc.pop();
                    else return false;
                }
                else {
                    if (!stc.empty() && stc.top() == '[') stc.pop();
                    else return false;
                }
            }
        }
        return stc.empty();
    }
};

int main() {
    Solution s;
    string k = "(){}}{";
    cout << s.isValid(k);
}
