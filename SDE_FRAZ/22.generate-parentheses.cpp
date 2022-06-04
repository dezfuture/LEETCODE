/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        if (n == 0)
        {
            return ans;
        }

        string temp = "";

        solve(n, ans, temp, 0, 0);
        return ans;
    }

private:
    void solve(int n, vector<string> &ans, string &temp, int open, int closed)
    {
        if (temp.size() == 2 * n)
        {
            ans.push_back(temp);
            return;
        }

        if (open < n)
        {
            int len = temp.size();
            temp += '(';
            solve(n, ans, temp, open + 1, closed);
            temp.resize(len);
        }
        if (open > closed)
        {
            int len = temp.size();
            temp += ')';
            solve(n, ans, temp, open, closed + 1);
            temp.resize(len);
        }
    }
};
// @lc code=end
