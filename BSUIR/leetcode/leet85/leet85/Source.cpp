#include <iostream>
#include <stack>
#include "vector"
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int x = matrix[0].size();
        int y = matrix.size();
        vector<vector<pair<int, int>>> dp(y, vector<pair<int,int>>(x));

        dp[y - 1][x - 1] = pair<int, int>(y - 1, x - 1);
        for (int i = x - 2; i > -1; --i) {
            if (matrix[y - 1][i] == '1') {
                if (dp[y - 1][i + 1] == pair<int, int >(-1, -1)) {
                    dp[y - 1][i] = pair<int, int >(y - 1, i);
                }
                else {
                    dp[y - 1][i] = dp[y - 1][i + 1];
                }
            }
            else {
                dp[y - 1][i] = pair<int, int >(-1, -1);
            }
        }
        for (int i = y - 2; i > -1; --i) {
            if (matrix[i][x - 1] == '1') {
                if (dp[i + 1][x - 1] == pair<int, int >(-1, -1)) {
                    dp[i][x - 1] = pair<int, int >(i, x - 1);
                }
                else {
                    dp[i][x - 1] = dp[i + 1][x - 1];
                }
            }
            else {
                dp[i][x - 1] = pair<int, int >(-1, -1);
            }
        }

        int maxi = 0;
        for (int i = y - 2; i > -1; --i) {
            for (int j = x - 2; j > -1; --j) {
                pair<int, int> dwn = dp[i + 1][j], rgt = dp[i][j + 1];
                if (matrix[i][j] == '1') {
                    if (dwn == pair<int, int >(-1, -1)) {
                        if (rgt == pair<int, int >(-1, -1)) {
                            dp[i][j] = pair<int, int >(i, j);
                            maxi = max(maxi, (dp[i][j].first - i + 1) * (dp[i][j].second - j + 1));
                        }
                        else {
                            dp[i][j] = pair<int, int >(i, rgt.second);
                            maxi = max(maxi, (dp[i][j].first - i + 1) * (dp[i][j].second - j + 1));
                        }
                    }
                    else if (rgt == pair<int, int >(-1, -1)){
                        dp[i][j] = pair<int, int >(dwn.first, j);
                        maxi = max(maxi, (dp[i][j].first - i + 1) * (dp[i][j].second - j + 1));
                    }
                    else {
                        if (dwn.second < rgt.second && dwn.first > rgt.first) {
                            if ((dwn.first - i + 1) * (dwn.second - j + 1)
                                > (rgt.first - i + 1) * (rgt.second - j + 1)) {
                                dp[i][j] = dwn;
                                maxi = max(maxi, (dwn.first - i + 1) * (dwn.second - j + 1));
                            }
                            else {
                                dp[i][j] = rgt;
                                maxi = max(maxi, (rgt.first - i + 1) * (rgt.second - j + 1));
                            }
                        }
                        else {
                            dp[i][j] = pair<int, int>(min(rgt.first, dwn.first), min(rgt.second, dwn.second));
                            maxi = max(maxi, (dp[i][j].first - i + 1) * (dp[i][j].second - j + 1));
                        }
                    }                
                }
                else {
                    dp[i][j] = pair<int, int >(-1, -1);          
                }
            }
        }

        return maxi;

    }
};

int main() {
    Solution s;
    vector<vector<char>> k = { {1, 0, 1, 0, 0},{1, 0, 1, 1, 1},{1, 1, 1, 1, 1}, {1, 0, 0, 1, 0} };
    cout << s.maximalRectangle(k);
}