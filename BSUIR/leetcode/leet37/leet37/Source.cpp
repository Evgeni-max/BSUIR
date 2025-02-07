#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int k = 0; k < 9; ++k) {
                if (board[i][k] == '.') {
                    for (int h = 1; h < 10; ++h) {
                        if (is_valid(board, i, k, h)) {
                            board[i][k] = 48 + h;
                            if (solve(board)) return true;
                        }
                    }
                    board[i][k] = '.';
                    return false;
                }
            }
        }
        return true;
    }

    bool is_valid(vector<vector<char>>& board, int row, int col, int num) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == 48 + num) return false;
        }
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == 48 + num) return false;
        }
        int st_row = row - row % 3, st_col = col - col % 3;
        
        for (int i = 0; i < 3; ++i) {
            for (int k = 0; k < 3; ++k) {
                if (board[st_row + i][st_col + k] == 48 + num) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<char>> k = {
       {'.', '9', '.', '.', '.', '.', '2', '.', '3'},
       {'.', '.', '8', '.', '.', '3', '.', '.', '.'},
       {'.', '6', '.', '4', '.', '.', '.', '.', '.'},
       {'.', '.', '.', '.', '8', '.', '1', '.', '.'},
       {'.', '.', '.', '.', '6', '.', '8', '9', '.'},
       {'.', '.', '.', '7', '5', '4', '.', '.', '.'},
       {'5', '.', '7', '.', '.', '.', '.', '.', '8'},
       {'.', '.', '.', '.', '.', '.', '.', '7', '.'},
       {'4', '.', '.', '.', '.', '6', '.', '5', '.'}
    };
    s.solveSudoku(k);
    for (const auto& row : k) {
        for (char c : row) {
            std::cout << c << ' ';
        }
        std::cout << std::endl;
    }
}