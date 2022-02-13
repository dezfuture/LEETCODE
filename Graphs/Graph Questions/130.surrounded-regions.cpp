/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<vector<char>> &board, int r, int c)
    {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == '#' || board[r][c] == 'X')
        {
            return;
        }

        board[r][c] = '#';

        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c - 1);
        dfs(board, r, c + 1);
    }

    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == 0 || i == m - 1 || j == n - 1 || j == 0) && (board[i][j] == 'O'))
                {
                    dfs(board, i, j);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
// @lc code=end
