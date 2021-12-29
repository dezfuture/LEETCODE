/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (42.95%)
 * Likes:    637
 * Dislikes: 85
 * Total Accepted:    417.7K
 * Total Submissions: 970.1K
 * Testcase Example:  '27'
 *
 * Given an integer n, return true if it is a power of three. Otherwise, return
 * false.
 *
 * An integer n is a power of three, if there exists an integer x such that n
 * == 3^x.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 27
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: n = 0
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: n = 9
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= n <= 2^31 - 1
 *
 *
 *
 * Follow up: Could you solve it without loops/recursion?
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (!n)
        {
            return false;
        }

        while (n % 3 == 0)
        {
            n /= 3;
        }

        return n == 1;
        }
};
// @lc code=end
