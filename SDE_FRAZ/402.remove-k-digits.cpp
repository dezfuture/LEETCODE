/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution
{
public:
    string removeKdigits(string v, int k)
    {
        int n = v.size();
        stack<char> s;
        string res = "";

        if (n <= k)
        {
            return "0";
        }

        s.push(v[0]);

        for (int i = 1; i < n; i++)
        {
            while (k > 0 && !s.empty() && v[i] < s.top())
            {
                s.pop();
                k--;
            }

            s.push(v[i]);

            if (s.size() == 1 && v[i] == '0')
            {
                s.pop();
            }
        }

        while (k && !s.empty())
        {
            s.pop();
            k--;
        }

        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }

        if (res.size() == 0)
        {
            return "0";
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end
