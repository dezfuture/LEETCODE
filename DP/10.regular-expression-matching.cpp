/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (28.07%)
 * Likes:    7227
 * Dislikes: 986
 * Total Accepted:    621K
 * Total Submissions: 2.2M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string s and a pattern p, implement regular expression
 * matching with support for '.' and '*' where:
 *
 *
 * '.' Matches any single character.​​​​
 * '*' Matches zero or more of the preceding element.
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
 * Input: s = "aa", p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 *
 *
 * Example 3:
 *
 *
 * Input: s = "ab", p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 20
 * 1 <= p.length <= 30
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '.', and '*'.
 * It is guaranteed for each appearance of the character '*', there will be a
 * previous valid character to match.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.length();
        int n = p.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return solve(s, p, 0, 0, dp);
    }

private:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= s.size() && j >= p.size())
        {
            return true;
        }
        if (j >= p.size())
        {
            return false;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');

        if ((j + 1) < p.size() && p[j + 1] == '*')
        {
            bool dontTake = solve(s, p, i, j + 2, dp);
            bool take = match ? solve(s, p, i + 1, j, dp) : false;
            return dp[i][j] = dontTake || take;
        }

        if (match)
        {
            return dp[i][j] = solve(s, p, i + 1, j + 1, dp);
        }

        return dp[i][j] = false;
    }
};

// DP SOLUTION

// class Solution
// {
// public:
//     bool isMatch(string s, string p)
//     {
//         int m = s.length();
//         int n = p.length();

//         bool dp[m + 1][n + 1];

//         dp[0][0] = true;

//         for (int i = 1; i < m + 1; i++)
//         {
//             dp[i][0] = false;
//         }

//         for (int i = 1; i < n + 1; i++)
//         {
//             if (p[i - 1] == '*')
//             {
//                 dp[0][i] = dp[0][i - 2];
//             }
//             else
//             {
//                 dp[0][] = false;
//             }
//         }

//         for (int i = 1; i < m + 1; i++)
//         {
//             for (int j = 1; j < n + 1; j++)
//             {
//                 if (p[j - 1] == '*')
//                 {
//                     dp[i][j] = dp[i][j - 2];

//                     if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
//                     {
//                         dp[i][j] = dp[i][j] || dp[i - 1][j];
//                     }
//                 }
//                 else if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
//                 {
//                     dp[i][j] = dp[i - 1][j - 1];
//                 }
//                 else
//                 {
//                     dp[i][j] = false;
//                 }
//             }
//         }

//         return dp[m][n];
//     }
// };
// @lc code=end
