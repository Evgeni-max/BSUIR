#include <iostream>
#include <stack>
#include "vector"
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int max = std::min(height[l], height[r]) * (r - l), legc;

        while (l < r) {
            legc = std::min(height[l], height[r]) * (r - l);
            if (max < legc) max = legc;

            if (height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> k = { 1,3,2,5,25,24,5 };
    cout << s.maxArea(k);
}
