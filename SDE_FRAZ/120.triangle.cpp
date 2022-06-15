/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution
{

    // ! leetcode 13 june 2022

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagnol = triangle[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(down, diagnol);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end
