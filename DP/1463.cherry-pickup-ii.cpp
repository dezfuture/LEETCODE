/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
 *
 * https://leetcode.com/problems/cherry-pickup-ii/description/
 *
 * algorithms
 * Hard (68.30%)
 * Likes:    1608
 * Dislikes: 15
 * Total Accepted:    48.5K
 * Total Submissions: 68.7K
 * Testcase Example:  '[[3,1,1],[2,5,1],[1,5,5],[2,1,1]]'
 *
 * You are given a rows x cols matrix grid representing a field of cherries
 * where grid[i][j] represents the number of cherries that you can collect from
 * the (i, j) cell.
 *
 * You have two robots that can collect cherries for you:
 *
 *
 * Robot #1 is located at the top-left corner (0, 0), and
 * Robot #2 is located at the top-right corner (0, cols - 1).
 *
 *
 * Return the maximum number of cherries collection using both robots by
 * following the rules below:
 *
 *
 * From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or
 * (i + 1, j + 1).
 * When any robot passes through a cell, It picks up all cherries, and the cell
 * becomes an empty cell.
 * When both robots stay in the same cell, only one takes the cherries.
 * Both robots cannot move outside of the grid at any moment.
 * Both robots should reach the bottom row in grid.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
 * Output: 24
 * Explanation: Path of robot #1 and #2 are described in color green and blue
 * respectively.
 * Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
 * Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
 * Total of cherries: 12 + 12 = 24.
 *
 *
 * Example 2:
 *
 *
 * Input: grid =
 * [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
 * Output: 28
 * Explanation: Path of robot #1 and #2 are described in color green and blue
 * respectively.
 * Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
 * Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
 * Total of cherries: 17 + 11 = 28.
 *
 *
 *
 * Constraints:
 *
 *
 * rows == grid.length
 * cols == grid[i].length
 * 2 <= rows, cols <= 70
 * 0 <= grid[i][j] <= 100
 *
 *
 */

// @lc code=start
// class Solution
// {
// public:
//     int dp[80][80][80];

//     int solve(vector<vector<int>> &grid, int r, int c1, int c2)
//     {
//         int m = grid.size();
//         int n = grid[0].size();

//         if (r == m)
//         {
//             return 0;
//         }

//         if (dp[r][c1][c2] != -1)
//         {
//             return dp[r][c1][c2];
//         }

//         int ans = 0;

//         for (int i = -1; i <= 1; i++)
//         {
//             for (int j = -1; j <= 1; j++)
//             {
//                 int C1 = c1 + i;
//                 int C2 = c2 + j;

//                 if (C1 >= 0 && C1 < m && C2 >= 0 && C2 < m)
//                 {
//                     ans = max(ans, solve(grid, r + 1, C1, C2));
//                 }
//             }
//         }

//         if (c1 == c2)
//         {
//             ans += grid[r][c1];
//         }
//         else
//         {
//             ans += (grid[r][c1] + grid[r][c2]);
//         }

//         return dp[r][c1][c2] = ans;
//     }

//     int cherryPickup(vector<vector<int>> &grid)
//     {
//         int m = grid.size();
//         int n = grid[0].size();

//         memset(dp, -1, sizeof(dp));

//         int res = solve(grid, 0, 0, n - 1);

//         return res;
//     }
// };

class Solution
{
public:
    int dp[80][80][80];
    int ok(vector<vector<int>> &grid, int c1, int c2, int r)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (r == n)
            return 0;
        if (dp[c1][c2][r] != -1)
            return dp[c1][c2][r];

        int ans = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int C1 = c1 + i;
                int C2 = c2 + j;
                if (C1 >= 0 && C1 < m && C2 >= 0 && C2 < m)
                {
                    ans = max(ans, ok(grid, C1, C2, r + 1));
                }
            }
        }
        if (c1 == c2)
            ans += grid[r][c1];
        else
            ans += (grid[r][c1] + grid[r][c2]);
        return dp[c1][c2][r] = ans;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        memset(dp, -1, sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();
        return ok(grid, 0, m - 1, 0);
    }
};
// @lc code=end
