/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (26.24%)
 * Likes:    4010
 * Dislikes: 177
 * Total Accepted:    351K
 * Total Submissions: 1.3M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*' where:
 *
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aa", p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "cb", p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length, p.length <= 2000
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '?' or '*'.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (s.size() == 0 && p.size() == 0)
        {
            return true;
        }
        if (p.size() == 0)
        {
            return false;
        }

        string res = "";
        res += p[0];

        for (int i = 1; i < p.length(); i++)
        {
            if (p[i] == p[i - 1] && p[i] == '*')
            {
                continue;
            }
            else
            {
                res += p[i];
            }
        }

        int m = s.length();
        int n = res.length();
        bool dp[m + 1][n + 1];

        // both are empty
        dp[0][0] = true;

        for (int i = 1; i < m + 1; i++)
        {
            dp[i][0] = false;
        }

        for (int j = 1; j < n + 1; j++)
        {
            dp[0][j] = false;
        }

        // case for the empty string s and only char at p being *
        if (p[0] == '*')
        {
            dp[0][1] = true;
        }

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (s[i - 1] == res[j - 1] || res[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    if (res[j - 1] == '*')
                    {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end
