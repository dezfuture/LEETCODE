/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int l = 0;
        int maxf = 0;
        int res = 0;
        vector<int> v(26, 0);

        for (int i = 0; i < n; i++)
        {
            v[s[i] - 'A']++;
            if (maxf < v[s[i] - 'A'])
            {
                maxf = v[s[i] - 'A'];
            }

            while (i - l + 1 - maxf > k)
            {
                v[s[l] - 'A']--;
                l++;
                for (int i = 0; i < 26; i++)
                {
                    if (maxf < v[i])
                    {
                        maxf = v[i];
                    }
                }
            }

            res = max(res, i - l + 1);
        }

        return res;
    }
};
// @lc code=end
