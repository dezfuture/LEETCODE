/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 *
 * https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
 *
 * algorithms
 * Hard (62.12%)
 * Likes:    1313
 * Dislikes: 23
 * Total Accepted:    37.2K
 * Total Submissions: 59.8K
 * Testcase Example:  '"zzazz"'
 *
 * Given a string s. In one step you can insert any character at any index of
 * the string.
 *
 * Return the minimum number of steps to make s palindrome.
 *
 * A Palindrome String is one that reads the same backward as well as
 * forward.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "zzazz"
 * Output: 0
 * Explanation: The string "zzazz" is already palindrome we don't need any
 * insertions.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "mbadm"
 * Output: 2
 * Explanation: String can be "mbdadbm" or "mdbabdm".
 *
 *
 * Example 3:
 *
 *
 * Input: s = "leetcode"
 * Output: 5
 * Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 500
 * s consists of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int minInsertions(string s)
    {
        string s1 = s;
        reverse(s.begin(), s.end());

        int n = s.length();

        int dp[n + 1][n + 1];

        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 0;
            dp[0][i] = 0;
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

        int res = n - dp[n][n];

        return res;
    }
};
// @lc code=end
