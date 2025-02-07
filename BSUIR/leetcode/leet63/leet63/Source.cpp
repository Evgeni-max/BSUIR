#include <iostream>
#include <stack>
#include "vector"
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size(); //столбцы
        int m = obstacleGrid.size(); //строки

        if (obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> dp(m);
        for (int i = 0; i < m; ++i) {
            dp[i] = vector<int>(n);
        }

        dp[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) dp[i][0] = 0;
            else dp[i][0] = dp[i - 1][0];
        }
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[0][i] == 1) dp[0][i] = 0;
            else dp[0][i] = dp[0][i - 1];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> k = { {0, 0, 0, 0},{0, 0, 1, 0},{0, 1, 0, 0}, {0, 1, 0, 0} };
    cout << s.uniquePathsWithObstacles(k);
}