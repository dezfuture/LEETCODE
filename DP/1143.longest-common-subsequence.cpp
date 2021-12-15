/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 *
 * https://leetcode.com/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (58.78%)
 * Likes:    4996
 * Dislikes: 58
 * Total Accepted:    312.3K
 * Total Submissions: 531.5K
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * Given two strings text1 and text2, return the length of their longest common
 * subsequence. If there is no common subsequence, return 0.
 *
 * A subsequence of a string is a new string generated from the original string
 * with some characters (can be none) deleted without changing the relative
 * order of the remaining characters.
 *
 *
 * For example, "ace" is a subsequence of "abcde".
 *
 *
 * A common subsequence of two strings is a subsequence that is common to both
 * strings.
 *
 *
 * Example 1:
 *
 *
 * Input: text1 = "abcde", text2 = "ace"
 * Output: 3
 * Explanation: The longest common subsequence is "ace" and its length is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: text1 = "abc", text2 = "abc"
 * Output: 3
 * Explanation: The longest common subsequence is "abc" and its length is 3.
 *
 *
 * Example 3:
 *
 *
 * Input: text1 = "abc", text2 = "def"
 * Output: 0
 * Explanation: There is no such common subsequence, so the result is 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= text1.length, text2.length <= 1000
 * text1 and text2 consist of only lowercase English characters.
 *
 *
 */

// @lc code=start

class Solution
{
public:
    int longestCommonSubsequence(string a, string b)
    {
        int m = a.length();
        int n = b.length();

        int dp[m + 1][n + 1];

        for (int i = 0; i < m + 1; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 0; i < n + 1; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (a[i - 1] == b[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

// MEMOIZATION SOLUTION

// class Solution
// {
// public:
//     int t[1001][1001];

//     int longestCommonSubsequence(string a, string b)
//     {
//         memset(t, -1, sizeof(t));
//         int res = lcs(a, b, a.length(), b.length());

//         return res;
//     }

// private:
//     int lcs(string a, string b, int m, int n)
//     {
//         if (m == 0 || n == 0)
//         {
//             return 0;
//         }

//         if (t[m][n] != -1)
//         {
//             return t[m][n];
//         }

//         if (a[m - 1] == b[n - 1])
//         {
//             return t[m][n] = 1 + lcs(a, b, m - 1, n - 1);
//         }
//         else
//         {
//             return t[m][n] = max(lcs(a, b, m - 1, n), lcs(a, b, m, n - 1));
//         }
//     }
// };

// RECURSIVE CODE

// class Solution
// {
// public:
//     int longestCommonSubsequence(string a, string b)
//     {
//         int m = a.length();
//         int n = b.length();

//         int res = solve(a, b, m, n);
//         return res;
//     }

// private:
//     int solve(string a, string b, int m, int n)
//     {
//         if (m == 0 || n == 0)
//         {
//             return 0;
//         }

//         if (a[m - 1] == b[n - 1])
//         {
//             return 1 + solve(a, b, m - 1, n - 1);
//         }
//         else
//         {
//             return max(solve(a, b, m - 1, n), solve(a, b, m, n - 1));
//         }

//         // return 0;
//     }
// };
// @lc code=end
