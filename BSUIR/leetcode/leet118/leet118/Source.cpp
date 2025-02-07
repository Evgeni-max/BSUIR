#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a;
        a[0].push_back(1);
        a.push_back(vector<int>());
        if (numRows > 1) {
            a.push_back(vector<int>());
            a[1].push_back(1);
            a[1].push_back(1);
            for (int i = 2; i < numRows; ++i) {
                a.push_back(vector<int>());
                a[i].push_back(1);
                int buf = a[i - 1].size() - 1;
                for (int h = 0; h < buf; ++h) {
                    a[i].push_back(a[i - 1][h] + a[i - 1][h + 1]);
                }
                a[i].push_back(1);
            }
        }
        return a;
    }
};

int main() {
    int numRows;
    cin >> numRows;
    vector<vector<int>> a;
    a.push_back(vector<int>());
    a[0].push_back(1);
    if (numRows > 1) {
        a.push_back(vector<int>());
        a[1].push_back(1);
        a[1].push_back(1);
        for (int i = 2; i < numRows; ++i) {
            a.push_back(vector<int>());
            a[i].push_back(1);
            int buf = a[i - 1].size() - 1;
            for (int h = 0; h < buf; ++h) {
                a[i].push_back(a[i - 1][h] + a[i - 1][h + 1]);
            }
            a[i].push_back(1);
        }
    }
}