/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &s)
    {
        int n = s.size();
        if (n == 0)
        {
            return "";
        }

        string res = "";

        sort(s.begin(), s.end());

        string a = s[0];
        string b = s[n - 1];

        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == b[i])
            {
                res += a[i];
            }
            else
            {
                break;
            }
        }

        return res;
    }
};
// @lc code=end
