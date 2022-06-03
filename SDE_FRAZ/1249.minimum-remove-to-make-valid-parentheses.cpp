/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<pair<char, int>> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push({s[i], i});
            }
            else if (s[i] == ')')
            {
                if (!st.empty() && st.top().first == '(')
                {
                    st.pop();
                }
                else
                {
                    st.push({s[i], i});
                }
            }
        }

        if (st.empty())
        {
            return s;
        }

        while (!st.empty())
        {
            int idx = st.top().second;

            s.erase(idx, 1);
            st.pop();
        }

        return s;
    }

    /*

    string a = "";
        int count = 0;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                count++;
            }
            else if (s[i] == ')')
            {
                if (count == 0)
                {
                    continue;
                }
                count--;
            }

            a += s[i];
        }

        string ans = "";
        int m = a.size();

        for (int i = m - 1; i >= 0; i--)
        {
            if (a[i] == '(' && count-- > 0)
            {
                continue;
            }

            ans += a[i];
        }

        reverse(ans.begin(), ans.end());

        return ans;


    */
};
// @lc code=end
