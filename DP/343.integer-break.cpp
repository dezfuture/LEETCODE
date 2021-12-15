/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (52.87%)
 * Likes:    2304
 * Dislikes: 301
 * Total Accepted:    164.1K
 * Total Submissions: 310.1K
 * Testcase Example:  '2'
 *
 * Given an integer n, break it into the sum of k positive integers, where k >=
 * 2, and maximize the product of those integers.
 *
 * Return the maximum product you can get.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 58
 *
 *
 */

// @lc code=start

//  DP SOLUTION

class Solution
{
public:
    int integerBreak(int n)
    {
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));

        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
            }
        }
        return dp[n];
    }
};

// MATHS & RECURSIVE SOLUTION
/*
class Solution
{
public:
    int integerBreak(int n)
    {
        if (n == 2)
        {
            return 1;
        }
        if (n == 3)
        {
            return 2;
        }
        if (n == 4)
        {
            return 4;
        }
        if (n == 5)
        {
            return 6;
        }
        if (n == 6)
        {
            return 9;
        }

        return 3 * integerBreak(n - 3);
    }
};*/

// @lc code=end
