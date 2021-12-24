/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 *
 * https://leetcode.com/problems/number-of-matching-subsequences/description/
 *
 * algorithms
 * Medium (50.04%)
 * Likes:    2422
 * Dislikes: 131
 * Total Accepted:    110.8K
 * Total Submissions: 220.9K
 * Testcase Example:  '"abcde"\n["a","bb","acd","ace"]'
 *
 * Given a string s and an array of strings words, return the number of
 * words[i] that is a subsequence of s.
 *
 * A subsequence of a string is a new string generated from the original string
 * with some characters (can be none) deleted without changing the relative
 * order of the remaining characters.
 *
 *
 * For example, "ace" is a subsequence of "abcde".
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcde", words = ["a","bb","acd","ace"]
 * Output: 3
 * Explanation: There are three strings in words that are a subsequence of s:
 * "a", "acd", "ace".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^4
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 50
 * s and words[i] consist of only lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int res = 0;
        unordered_map<string, int> m;
        for (int i = 0; i < words.size(); i++)
        {
            m[words[i]]++;
        }

        for (auto it = m.begin(); it != m.end(); ++it)
        {
            if (solve(s, it->first))
            {
                res += it->second;
            }
        }

        return res;
    }

private:
    bool solve(string a, string b)
    {
        int i = 0, j = 0;
        int m = a.length();
        int n = b.length();

        while (i < m && j < n)
        {
            if (a[i] == b[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }

        return (j == n);
    }
};

// class Solution
// {
// public:
//     int numMatchingSubseq(string s, vector<string> &words)
//     {
//         vector<vector<int>> v(26);
//         int res = 0;
//         for (int i = 0; i < s.length(); i++)
//         {
//             v[s[i] - 'a'].push_back(i);
//         }

//         for (auto &word : words)
//         {
//             int prev = -1;
//             bool flag = true;

//             for (auto &c : word)
//             {
//                 auto it = upper_bound(v[c - 'a'].begin(), v[c - 'a'].end(), prev);
//                 if (it == v[c - 'a'].end())
//                 {
//                     flag = false;
//                     break;
//                 }

//                 prev = *it;
//             }

//             if (flag)
//             {
//                 res++;
//             }
//         }

//         return res;
//     }
// };
// @lc code=end
