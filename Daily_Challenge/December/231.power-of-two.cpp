/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (44.13%)
 * Likes:    2551
 * Dislikes: 264
 * Total Accepted:    540K
 * Total Submissions: 1.2M
 * Testcase Example:  '1'
 *
 * Given an integer n, return true if it is a power of two. Otherwise, return
 * false.
 *
 * An integer n is a power of two, if there exists an integer x such that n ==
 * 2^x.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 1
 * Output: true
 * Explanation: 2^0 = 1
 *
 *
 * Example 2:
 *
 *
 * Input: n = 16
 * Output: true
 * Explanation: 2^4 = 16
 *
 *
 * Example 3:
 *
 *
 * Input: n = 3
 * Output: false
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
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        return ((n & (n - 1)) == 0);
    }
};

// sol 1
// class Solution
// {
// public:
//     bool isPowerOfTwo(int n)
//     {
//         if (n == 0)
//         {
//             return false;
//         }

//         while (n % 2 == 0)
//         {
//             n /= 2;
//         }

//         return n == 1;
//     }
// };
// @lc code=end
