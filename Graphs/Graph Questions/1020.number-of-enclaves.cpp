/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start

// !DFS Solution

class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int all_one = 0, boundary_one = 0;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                all_one += grid[i][j];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1)
                {
                    boundary_one += dfs(grid, i, j);
                }
            }
        }

        return all_one - boundary_one;
    }

private:
    int dfs(vector<vector<int>> &grid, int row, int col)
    {

        int m = grid.size();
        int n = grid[0].size();

        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0)
        {
            return 0;
        }

        grid[row][col] = 0;

        return 1 + dfs(grid, row + 1, col) + dfs(grid, row - 1, col) + dfs(grid, row, col + 1) + dfs(grid, row, col - 1);
    }
};
// @lc code=end
