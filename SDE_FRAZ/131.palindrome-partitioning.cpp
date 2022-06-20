/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> res;
        dfs(ans, res, s, 0);
        return ans;
    }

private:
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    void dfs(vector<vector<string>> &ans, vector<string> &res, string &s, int i)
    {
        if (i >= s.size())
        {
            ans.push_back(res);
            return;
        }

        for (int j = i; j < s.size(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                res.push_back(s.substr(i, j - i + 1));
                dfs(ans, res, s, j + 1);
                res.pop_back();
            }
        }
    }
};
// @lc code=end
