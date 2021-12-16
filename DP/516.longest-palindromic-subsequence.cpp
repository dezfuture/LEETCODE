/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (58.20%)
 * Likes:    4377
 * Dislikes: 237
 * Total Accepted:    218.9K
 * Total Submissions: 375.7K
 * Testcase Example:  '"bbbab"'
 *
 * Given a string s, find the longest palindromic subsequence's length in s.
 *
 * A subsequence is a sequence that can be derived from another sequence by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "bbbab"
 * Output: 4
 * Explanation: One possible longest palindromic subsequence is "bbbb".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbbd"
 * Output: 2
 * Explanation: One possible longest palindromic subsequence is "bb".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consists only of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        string s1 = s;
        reverse(s.begin(), s.end());

        int n = s.length();

        int dp[n + 1][n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            dp[0][i] = 0;
            dp[i][0] = 0;
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (s[i - 1] == s1[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int temp = dp[n][n];

        return temp;
    }
};
// @lc code=end
