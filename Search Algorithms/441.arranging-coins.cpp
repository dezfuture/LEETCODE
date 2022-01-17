/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 *
 * https://leetcode.com/problems/arranging-coins/description/
 *
 * algorithms
 * Easy (44.75%)
 * Likes:    1846
 * Dislikes: 968
 * Total Accepted:    254.5K
 * Total Submissions: 567.3K
 * Testcase Example:  '5'
 *
 * You have n coins and you want to build a staircase with these coins. The
 * staircase consists of k rows where the i^th row has exactly i coins. The
 * last row of the staircase may be incomplete.
 *
 * Given the integer n, return the number of complete rows of the staircase you
 * will build.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 5
 * Output: 2
 * Explanation: Because the 3^rd row is incomplete, we return 2.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 8
 * Output: 3
 * Explanation: Because the 4^th row is incomplete, we return 3.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int arrangeCoins(int n)
    {
        int low = 1, high = n;
        while (low <= high)
        {
            long long int mid = low + (high - low) / 2;

            long long int curr = (mid * (mid + 1)) / 2;

            if (curr == n)
            {
                return mid;
            }
            else if (curr < n)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return high;
    }
};
// @lc code=end
