/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (41.62%)
 * Likes:    6336
 * Dislikes: 135
 * Total Accepted:    441.6K
 * Total Submissions: 1M
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given an m x n binary matrix filled with 0's and 1's, find the largest
 * square containing only 1's and return its area.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [["0","1"],["1","0"]]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: matrix = [["0"]]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 300
 * matrix[i][j] is '0' or '1'.
 *
 *
 */

// @lc code=start

// DP SOLUTION

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int res = 0;

        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (matrix[i - 1][j - 1] == '0')
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
                }

                res = max(res, dp[i][j]);
            }
        }

        return res * res;
    }
};

// BRUTE FORCE SOLUTION
/*
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxLen = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    int sqLen = 1;
                    bool flag = true;

                    while (sqLen + i < m && sqLen + j < n && flag)
                    {
                        for (int k = j; k <= sqLen + j; k++)
                        {
                            if (matrix[i + sqLen][k] == '0')
                            {
                                flag = false;
                                break;
                            }
                        }

                        for (int k = i; k <= sqLen + i; k++)
                        {
                            if (matrix[k][j + sqLen] == '0')
                            {
                                flag = false;
                                break;
                            }
                        }

                        if (flag)
                        {
                            sqLen++;
                        }
                    }

                    if (maxLen < sqLen)
                    {
                        maxLen = sqLen;
                    }
                }
            }
        }
        return maxLen * maxLen;
    }
};

*/

// @lc code=end
