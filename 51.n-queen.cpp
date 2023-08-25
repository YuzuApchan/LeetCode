#include <vector>
#include <string>

using namespace std;
/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board = {"....", "....", "....", "...."};
        backtrack(0, board);
        return res;
    }
    void backtrack(int row, vector<string> &board)
    {
        if (row < board.size())
        {
            int maxLength = board[row].size();
            for (int col = 0; col < maxLength; col++)
            {
                if (true == isValid(row, col, board))
                {
                    board[row][col] = 'Q';
                    backtrack(row + 1, board);
                    board[row][col] = '.';
                }
            }
        }
        else
        {
            res.push_back(board);
            return;
        }
    }
    bool isValid(int row, int col, vector<string> &board)
    {
        for (int idx = 0; idx < row; idx++)
        {
            int maxLength = board[idx].size();
            if (board[idx][col] == 'Q')
            {
                return false;
            }
            else if (col - (row - idx) >= 0 && board[idx][col - (row - idx)] == 'Q')
            {
                return false;
            }
            else if (col + (row - idx) < maxLength && board[idx][col + (row - idx)] == 'Q')
            {
                return false;
            }
            else
            {
                continue;
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    solution.solveNQueens(8);
    return 0;
}

