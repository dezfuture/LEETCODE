/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
class Solution
{
public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int count = 0;
        int m = grid2.size();
        int n = grid2[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] == 1)
                {
                    bool res = true;
                    dfs(grid1, grid2, i, j, res);
                    if (res)
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }

private:
    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int row, int col, bool &res)
    {
        int m = grid2.size();
        int n = grid2[0].size();

        if (row < 0 || col < 0 || row >= m || col >= n || grid2[row][col] != 1)
        {
            return;
        }

        grid2[row][col] = 0;

        if (grid1[row][col] != 1)
        {
            res = false;
        }

        dfs(grid1, grid2, row + 1, col, res);
        dfs(grid1, grid2, row - 1, col, res);
        dfs(grid1, grid2, row, col + 1, res);
        dfs(grid1, grid2, row, col - 1, res);
    }
};
// @lc code=end
