/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        solve(0, board, ans, n);

        return ans;
    }

private:
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int dupRow = row, dupCol = col;

        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }

            row--;
            col--;
        }

        row = dupRow;
        col = dupCol;

        while (col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }

            col--;
        }

        col = dupCol;

        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }

            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
};
// @lc code=end
