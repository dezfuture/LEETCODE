/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 *
 * https://leetcode.com/problems/number-complement/description/
 *
 * algorithms
 * Easy (65.51%)
 * Likes:    1803
 * Dislikes: 99
 * Total Accepted:    251.5K
 * Total Submissions: 378.7K
 * Testcase Example:  '5'
 *
 * The complement of an integer is the integer you get when you flip all the
 * 0's to 1's and all the 1's to 0's in its binary representation.
 *
 *
 * For example, The integer 5 is "101" in binary and its complement is "010"
 * which is the integer 2.
 *
 *
 * Given an integer num, return its complement.
 *
 *
 * Example 1:
 *
 *
 * Input: num = 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits),
 * and its complement is 010. So you need to output 2.
 *
 *
 * Example 2:
 *
 *
 * Input: num = 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and
 * its complement is 0. So you need to output 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= num < 2^31
 *
 *
 *
 * Note: This question is the same as 1009:
 * https://leetcode.com/problems/complement-of-base-10-integer/
 *
 */

// @lc code=start
class Solution
{
public:
    int findComplement(int num)
    {
        unsigned int pow2 = 2, temp = num;

        while (temp >> 1)
        {
            temp >>= 1;
            pow2 <<= 1;
        }

        return pow2 - num - 1;
    }
};
// @lc code=end
