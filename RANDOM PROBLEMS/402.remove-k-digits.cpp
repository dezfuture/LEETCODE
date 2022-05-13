/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int len = num.size();

        if (len <= k)
        {
            return "0";
        }

        if (k == 0)
        {
            return num;
        }

        string res = "";
        stack<char> s;

        s.push(num[0]);

        for (int i = 1; i < len; i++)
        {
            while (k > 0 && !s.empty() && num[i] < s.top())
            {
                k--;
                s.pop();
            }

            s.push(num[i]);

            if (s.size() == 1 && num[i] == '0')
            {
                s.pop();
            }
        }

        while (k && !s.empty())
        {
            k--;
            s.pop();
        }

        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }

        reverse(res.begin(), res.end());

        if (res.size() == 0)
        {
            return "0";
        }

        return res;
    }
};
// @lc code=end
