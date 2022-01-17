/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (42.67%)
 * Likes:    1853
 * Dislikes: 217
 * Total Accepted:    323.6K
 * Total Submissions: 756.7K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 *
 * Follow up: Do not use any built-in library function such as sqrt.
 *
 *
 * Example 1:
 * Input: num = 16
 * Output: true
 * Example 2:
 * Input: num = 14
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= num <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int low = 1, high = num;

        long long int mid = low + (high - low) / 2;

        while (low <= high)
        {
            long long int square = mid * mid;
            if (square == num)
            {
                return true;
            }
            else if (square < num)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            mid = low + (high - low) / 2;
        }
        return false;
    }
};
// @lc code=end
