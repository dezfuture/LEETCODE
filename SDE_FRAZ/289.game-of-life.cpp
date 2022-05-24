/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {

        int m = board.size(), n = board[0].size(), nbors = 0, x = 0, y = 0;
        vector<pair<int, int>> moves = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                nbors = 0;
                for (int k = 0; k < 8; k++)
                {
                    x = i + moves[k].first, y = j + moves[k].second;
                    if (x >= 0 && x <= m - 1 && y >= 0 && y <= n - 1 && board[x][y] % 10)
                        nbors++;
                }
                board[i][j] += 10 * nbors;
            }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = (board[i][j] == 21 || board[i][j] / 10 == 3) ? 1 : 0;
    }
};

// @lc code=end
