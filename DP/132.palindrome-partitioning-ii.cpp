/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 *
 * https://leetcode.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (32.88%)
 * Likes:    2881
 * Dislikes: 75
 * Total Accepted:    191.6K
 * Total Submissions: 581.9K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aab"
 * Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using
 * 1 cut.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "a"
 * Output: 0
 *
 *
 * Example 3:
 *
 *
 * Input: s = "ab"
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 2000
 * s consists of lower-case English letters only.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int t[2001][2001];
    int minCut(string s)
    {

        memset(t, -1, sizeof(t));
        int ans = solve(s, 0, s.length() - 1);

        return ans;
    }

private:
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string s, int i, int j)
    {
        if (i >= j)
        {
            return 0;
        }

        if (isPalindrome(s, i, j))
        {
            return 0;
        }

        if (t[i][j] != -1)
        {
            return t[i][j];
        }

        int res = INT_MAX;

        for (int k = i; k < j; k++)
        {
            // int temp = solve(s, i, k) + solve(s, k + 1, j) + 1;

            if (isPalindrome(s, i, k))
            {
                int temp = solve(s, k + 1, j) + 1;
                res = min(res, temp);
            }
        }

        return t[i][j] = res;
    }
};
// @lc code=end
