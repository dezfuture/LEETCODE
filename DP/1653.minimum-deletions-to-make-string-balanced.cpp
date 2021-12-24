/*
 * @lc app=leetcode id=1653 lang=cpp
 *
 * [1653] Minimum Deletions to Make String Balanced
 *
 * https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/
 *
 * algorithms
 * Medium (54.21%)
 * Likes:    524
 * Dislikes: 14
 * Total Accepted:    14.2K
 * Total Submissions: 26.1K
 * Testcase Example:  '"aababbab"'
 *
 * You are given a string s consisting only of characters 'a' and 'b'​​​​.
 *
 * You can delete any number of characters in s to make s balanced. s is
 * balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b'
 * and s[j]= 'a'.
 *
 * Return the minimum number of deletions needed to make s balanced.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aababbab"
 * Output: 2
 * Explanation: You can either:
 * Delete the characters at 0-indexed positions 2 and 6 ("aababbab" ->
 * "aaabbb"), or
 * Delete the characters at 0-indexed positions 3 and 6 ("aababbab" ->
 * "aabbbb").
 *
 *
 * Example 2:
 *
 *
 * Input: s = "bbaaaaabb"
 * Output: 2
 * Explanation: The only solution is to delete the first two characters.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] is 'a' or 'b'​​.
 *
 *
 */

// @lc code=start

// CRAZY SOLUTION (LOL)

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int a_count = 0, b_count = 0;
        for (auto &c : s)
        {
            if (c == 'a')
            {
                a_count++;
            }
        }

        int res = a_count;

        for (auto &c : s)
        {
            if (c == 'b')
            {
                b_count++;
            }
            else
            {
                a_count--;
            }

            res = min(res, (a_count + b_count));
        }
        return res;
    }
};
// @lc code=end
