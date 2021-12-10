/*
 * @lc app=leetcode id=2035 lang=cpp
 *
 * [2035] Partition Array Into Two Arrays to Minimize Sum Difference
 *
 * https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/
 *
 * algorithms
 * Hard (24.53%)
 * Likes:    255
 * Dislikes: 10
 * Total Accepted:    3.5K
 * Total Submissions: 14.2K
 * Testcase Example:  '[3,9,7,3]'
 *
 * You are given an integer array nums of 2 * n integers. You need to partition
 * nums into two arrays of length n to minimize the absolute difference of the
 * sums of the arrays. To partition nums, put each element of nums into one of
 * the two arrays.
 *
 * Return the minimum possible absolute difference.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,9,7,3]
 * Output: 2
 * Explanation: One optimal partition is: [3,9] and [7,3].
 * The absolute difference between the sums of the arrays is abs((3 + 9) - (7 +
 * 3)) = 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-36,36]
 * Output: 72
 * Explanation: One optimal partition is: [-36] and [36].
 * The absolute difference between the sums of the arrays is abs((-36) - (36))
 * = 72.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [2,-1,0,4,-2,-9]
 * Output: 0
 * Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
 * The absolute difference between the sums of the arrays is abs((2 + 4 + -9) -
 * (-1 + 0 + -2)) = 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 15
 * nums.length == 2 * n
 * -10^7 <= nums[i] <= 10^7
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

        for (int i = 0; i < sum + 1; i++)
        {
            dp[0][i] = false;
        }

        for (int i = 1; i < n + 1; i++)
        {
            dp[i][0] = true;
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        int res = INT_MAX;

        for (int i = 0; i < sum + 1; i++)
        {
            if (dp[n][i])
            {
                res = min(res, abs(i - (sum - i)));
            }
        }

        return res;
    }
};
// @lc code=end
