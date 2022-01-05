/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (56.19%)
 * Likes:    5028
 * Dislikes: 154
 * Total Accepted:    379.6K
 * Total Submissions: 671.3K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome. Return all possible palindrome partitioning of s.
 *
 * A palindrome string is a string that reads the same backward as forward.
 *
 *
 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
 *
 *
 */

// @lc code=start

// DP + BACKTRACKING

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        int len = s.length();

        vector<vector<bool>> dp(len, vector<bool>(len, false));
        vector<vector<string>> res;

        vector<string> temp;

        dfs(res, s, 0, temp, dp);

        return res;
    }

private:
    void dfs(vector<vector<string>> &res, string &s, int i, vector<string> &temp, vector<vector<bool>> &dp)
    {
        if (i >= s.length())
        {
            res.push_back(temp);
        }

        for (int j = i; j < s.length(); j++)
        {
            if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]))
            {
                dp[i][j] = true;
                temp.push_back(s.substr(i, j - i + 1));
                dfs(res, s, j + 1, temp, dp);
                temp.pop_back();
            }
        }
    }
};

// BACKTRACKING SOLUTION

// class Solution
// {
// public:
//     vector<vector<string>> partition(string s)
//     {
//         vector<vector<string>> res;
//         vector<string> temp;
//         dfs(res, s, 0, temp);

//         return res;
//     }

// private:
//     bool isPalindrome(string &s, int i, int j)
//     {
//         while (i < j)
//         {
//             if (s[i] != s[j])
//                 return false;
//             i++;
//             j--;
//         }
//         return true;
//     }

//     void dfs(vector<vector<string>> &res, string &s, int i, vector<string> &temp)
//     {
//         if (i >= s.length())
//         {
//             res.push_back(temp);
//         }

//         for (int j = i; j < s.length(); j++)
//         {
//             if (isPalindrome(s, i, j))
//             {
//                 temp.push_back(s.substr(i, j - i + 1));

//                 dfs(res, s, j + 1, temp);

//                 temp.pop_back();
//             }
//         }
//     }
// };
// @lc code=end
