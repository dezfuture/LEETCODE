/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (31.51%)
 * Likes:    14740
 * Dislikes: 861
 * Total Accepted:    1.6M
 * Total Submissions: 5M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbbd"
 * Output: "bb"
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a"
 * Output: "a"
 *
 *
 * Example 4:
 *
 *
 * Input: s = "ac"
 * Output: "a"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 *
 *
 */

// @lc code=start

// DP SOLUTION

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        bool table[n][n];

        // to initialize table with value 0
        memset(table, 0, sizeof(table));

        int maxLength = 0;
        int start = 0;

        // for all substring of size 1
        for (int i = 0; i < n; i++)
        {
            table[i][i] = 1;
            start = 0;
            maxLength = 1;
        }

        // for all substring of size 2
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                table[i][i + 1] = 1;
                start = i;
                maxLength = 2;
            }
        }

        // for all substring of size 3-n
        for (int k = 2; k < n; k++)
        {
            int beg = 0;
            int end = k;
            for (; end < n; beg++, end++)
            {
                if (s[beg] == s[end] && table[beg + 1][end - 1])
                {
                    table[beg][end] = 1;
                    if ((k + 1) > maxLength)
                    {
                        maxLength = k + 1;
                        start = beg;
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }
};

// @lc code=end