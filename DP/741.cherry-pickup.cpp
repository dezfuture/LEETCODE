/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
 *
 * https://leetcode.com/problems/cherry-pickup/description/
 *
 * algorithms
 * Hard (36.02%)
 * Likes:    2299
 * Dislikes: 115
 * Total Accepted:    48.5K
 * Total Submissions: 134.6K
 * Testcase Example:  '[[0,1,-1],[1,0,-1],[1,1,1]]'
 *
 * You are given an n x n grid representing a field of cherries, each cell is
 * one of three possible integers.
 *
 *
 * 0 means the cell is empty, so you can pass through,
 * 1 means the cell contains a cherry that you can pick up and pass through,
 * or
 * -1 means the cell contains a thorn that blocks your way.
 *
 *
 * Return the maximum number of cherries you can collect by following the rules
 * below:
 *
 *
 * Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right
 * or down through valid path cells (cells with value 0 or 1).
 * After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up
 * through valid path cells.
 * When passing through a path cell containing a cherry, you pick it up, and
 * the cell becomes an empty cell 0.
 * If there is no valid path between (0, 0) and (n - 1, n - 1), then no
 * cherries can be collected.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
 * Output: 5
 * Explanation: The player started at (0, 0) and went down, down, right right
 * to reach (2, 2).
 * 4 cherries were picked up during this single trip, and the matrix becomes
 * [[0,1,-1],[0,0,-1],[0,0,0]].
 * Then, the player went left, up, up, left to return home, picking up one more
 * cherry.
 * The total number of cherries picked up is 5, and this is the maximum
 * possible.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 50
 * grid[i][j] is -1, 0, or 1.
 * grid[0][0] != -1
 * grid[n - 1][n - 1] != -1
 *
 *
 */

// @lc code=start

// MEMOIZTION

class Solution
{
public:
    int n;
    int dp[51][51][51][51];

    int cherryPickup(vector<vector<int>> &grid)
    {
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        int res = solve(grid, 0, 0, 0, 0);

        return res >= 0 ? res : 0;
    }

private:
    int solve(vector<vector<int>> &grid, int r1, int c1, int r2, int c2)
    {
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
        {
            return INT32_MIN;
        }

        if (dp[r1][c1][r2][c2] != -1)
        {
            return dp[r1][c1][r2][c2];
        }

        int cherries = 0;

        if (r1 == n - 1 && c1 == n - 1)
        {
            return grid[r1][c1];
        }

        if (r1 == r2 && c1 == c2)
        {
            cherries += grid[r1][c1];
        }
        else
        {
            cherries += grid[r1][c1] + grid[r2][c2];
        }

        int a = solve(grid, r1 + 1, c1, r2 + 1, c2);
        int b = solve(grid, r1 + 1, c1, r2, c2 + 1);
        int c = solve(grid, r1, c1 + 1, r2 + 1, c2);
        int d = solve(grid, r1, c1 + 1, r2, c2 + 1);

        return dp[r1][c1][r2][c2] = cherries + max(max(a, b), max(c, d));
    }
};

// backtracking solution (tle)
/*

class Solution
{
public:
    int res = 0;
    int cherryPickup(vector<vector<int>> &grid)
    {

        if (grid.size() == 1)
        {
            return grid[0][0] == 1 ? 1 : 0;
        }
        firstIteration(grid, 0, 0, 0);

        return res;
    }

private:
    void firstIteration(vector<vector<int>> &grid, int row, int col, int ccsf)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == -1)
        {
            return;
        }

        if (row == grid.size() - 1 && col == grid[0].size() - 1)
        {
            secondIteration(grid, row, col, ccsf);
        }

        int cherries = grid[row][col];
        grid[row][col] = 0;
        firstIteration(grid, row + 1, col, ccsf + cherries);
        firstIteration(grid, row, col + 1, ccsf + cherries);

        grid[row][col] = cherries;
    }

    void secondIteration(vector<vector<int>> &grid, int row, int col, int ccsf)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == -1)
        {
            return;
        }

        if (row == 0 && col == 0)
        {
            res = max(res, ccsf);
            return;
        }

        int cherries = grid[row][col];
        grid[row][col] = 0;
        secondIteration(grid, row - 1, col, ccsf + cherries);
        secondIteration(grid, row, col - 1, ccsf + cherries);
        grid[row][col] = cherries;
    }
};

*/
// @lc code=end
