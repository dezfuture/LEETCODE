/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word == "")
        {
            return false;
        }

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0] && solve(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool solve(vector<vector<char>> &board, string word, int i, int j, int n)
    {
        if (n == word.size())
        {
            return true;
        }

        if (i < 0 || i > board.size() || j < 0 || j > board[0].size() || board[i][j] != word[n])
        {
            return false;
        }

        board[i][j] = 0;

        bool flag = solve(board, word, i + 1, j, n + 1) ||
                    solve(board, word, i, j + 1, n + 1) ||
                    solve(board, word, i, j - 1, n + 1) ||
                    solve(board, word, i - 1, j, n + 1);

        board[i][j] = word[n];

        return flag;
    }
};
// @lc code=end
