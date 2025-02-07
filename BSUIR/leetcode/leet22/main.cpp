#include <iostream>
#include <stack>
#include "vector"
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        recursive(1, 0, "(");
        return vectorStr;
    }
    void recursive(int left, int right, string str) {
        if (left == n) {
            if (right == n) vectorStr.push_back(str);
            else recursive(left, right + 1, str + ')');
        }
        else {
            recursive(left + 1, right, str + '(');
            if (left > right) recursive(left, right + 1, str + ')');
        }
    }
private:
    int n;
    vector<string> vectorStr;
};

int main() {
    Solution s;
    vector<string> k = s.generateParenthesis(10);
    for (int i = 0; i < k.size(); ++i) {
        cout << k[i] << '\n';
    }
}
