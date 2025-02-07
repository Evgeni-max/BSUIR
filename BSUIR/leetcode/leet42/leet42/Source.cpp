#include <iostream>
#include <stack>
#include "vector"
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max(height.size()), right_max(height.size());

        left_max[0] = height[0]; right_max[height.size() - 1] = height[height.size() - 1];
        for (int i = 1; i < height.size(); ++i) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        for (int i = height.size() - 2; i > -1; --i) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        int wet = 0;
        for (int i = 1; i < height.size(); ++i) {
            wet += min(left_max[i], right_max[i]) - height[i];
        }

        return wet;
    }
};

int main() {
    Solution s;
    vector<int> k = { 4,2,0,3,2,5 };
    cout << s.trap(k);
}