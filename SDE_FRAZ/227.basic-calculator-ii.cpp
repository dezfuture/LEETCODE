/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        int n = s.size();
        stack<int> st;
        char sign = '+';

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }

            if (isdigit(s[i]))
            {
                int val = 0;
                while (i < n && isdigit(s[i]))
                {
                    val = 10 * val + (s[i] - '0');
                    i++;
                }
                i--;

                if (sign == '+')
                {
                    st.push(val);
                }
                else if (sign == '-')
                {
                    st.push(-val);
                }
                else if (sign == '*')
                {
                    int top = st.top();
                    st.pop();
                    st.push(top * val);
                }
                else if (sign == '/')
                {
                    int top = st.top();
                    st.pop();
                    st.push(top / val);
                }
            }

            else if (s[i] != ' ')
            {
                sign = s[i];
            }
        }

        int res = 0;
        while (!st.empty())
        {
            int hell = st.top();
            st.pop();
            res += hell;
        }

        return res;
    }
};
// @lc code=end
