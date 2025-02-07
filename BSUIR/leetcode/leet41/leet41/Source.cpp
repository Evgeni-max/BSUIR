#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int x, sz = nums.size();

        for (int i = 0; i < sz; ++i) {
             x = nums[i];
             if (x < 1 || x > sz) continue;
             while (nums[x - 1] != x) {
                 swap(nums[x - 1], x);
                 if (x < 1 || x > sz) break;
             }
        }

        for (int i = 0; i < sz - 1; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        if (nums[sz - 1] != sz) return sz;
        else return sz + 1;
    }
};

int main() {
    Solution s;
    std::vector<int> k = { 2,1,3,6,7,4,5 };
    cout << '\n' << s.firstMissingPositive(k);
}