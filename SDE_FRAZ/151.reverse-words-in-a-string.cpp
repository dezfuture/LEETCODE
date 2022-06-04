/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());

        int i = 0, r = 0, l = 0, len = s.size();
        while (i < len)
        {
            while (i < len && s[i] != ' ')
            {
                s[r++] = s[i++];
            }

            if (l < r)
            {
                reverse(s.begin() + l, s.begin() + r);
                if (r == len)
                {
                    break;
                }
                s[r++] = ' ';
                l = r;
            }

            i++;
        }

        if (r > 0 && s[r - 1] == ' ')
        {
            r--;
        }

        s.resize(r);

        return s;
    }
};
// @lc code=end
