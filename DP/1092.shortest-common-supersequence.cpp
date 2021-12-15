/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence
 *
 * https://leetcode.com/problems/shortest-common-supersequence/description/
 *
 * algorithms
 * Hard (55.11%)
 * Likes:    1715
 * Dislikes: 35
 * Total Accepted:    36.2K
 * Total Submissions: 65.6K
 * Testcase Example:  '"abac"\n"cab"'
 *
 * Given two strings str1 and str2, return the shortest string that has both
 * str1 and str2 as subsequences. If there are multiple valid strings, return
 * any of them.
 *
 * A string s is a subsequence of string t if deleting some number of
 * characters from t (possibly 0) results in the string s.
 *
 *
 * Example 1:
 *
 *
 * Input: str1 = "abac", str2 = "cab"
 * Output: "cabac"
 * Explanation:
 * str1 = "abac" is a subsequence of "cabac" because we can delete the first
 * "c".
 * str2 = "cab" is a subsequence of "cabac" because we can delete the last
 * "ac".
 * The answer provided is the shortest such string that satisfies these
 * properties.
 *
 *
 * Example 2:
 *
 *
 * Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
 * Output: "aaaaaaaa"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= str1.length, str2.length <= 1000
 * str1 and str2 consist of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    string shortestCommonSupersequence(string a, string b)
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

        string s = "";
        int i = m, j = n;

        while (i > 0 && j > 0)
        {
            if (a[i - 1] == b[j - 1])
            {
                s.push_back(a[i - 1]);
                i--;
                j--;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    s.push_back(a[i - 1]);
                    i--;
                }
                else
                {
                    s.push_back(b[j - 1]);
                    j--;
                }
            }
        }

        while (i > 0)
        {
            s.push_back(a[i - 1]);
            i--;
        }

        while (j > 0)
        {
            s.push_back(b[j - 1]);
            j--;
        }

        reverse(s.begin(), s.end());

        return s;
    }
};
// @lc code=end
