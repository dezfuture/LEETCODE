/*
 * @lc app=leetcode id=1446 lang=cpp
 *
 * [1446] Consecutive Characters
 *
 * https://leetcode.com/problems/consecutive-characters/description/
 *
 * algorithms
 * Easy (61.08%)
 * Likes:    1103
 * Dislikes: 22
 * Total Accepted:    109K
 * Total Submissions: 175.7K
 * Testcase Example:  '"leetcode"'
 *
 * The power of the string is the maximum length of a non-empty substring that
 * contains only one unique character.
 *
 * Given a string s, return the power of s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leetcode"
 * Output: 2
 * Explanation: The substring "ee" is of length 2 with the character 'e'
 * only.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abbcccddddeeeeedcba"
 * Output: 5
 * Explanation: The substring "eeeee" is of length 5 with the character 'e'
 * only.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "triplepillooooow"
 * Output: 5
 *
 *
 * Example 4:
 *
 *
 * Input: s = "hooraaaaaaaaaaay"
 * Output: 11
 *
 *
 * Example 5:
 *
 *
 * Input: s = "tourist"
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 500
 * s consists of only lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int maxPower(string s)
    {
        int len = s.length();
        int res = 1, temp = 0;

        if (len == 1)
        {
            return 1;
        }
        for (int i = 0; i < len - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                res++;
            }
            else
            {
                res = 1;
            }

            temp = max(temp, res);
        }

        return temp;
    }
};
// @lc code=end
