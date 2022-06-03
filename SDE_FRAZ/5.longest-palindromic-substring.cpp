/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution
{
public:
    // ? dp

    string longestPalindrome(string s)
    {
        }

    // ? expanding from the middle
    /*
        string longestPalindrome(string s)
        {
            int n = s.size();
            string res = "";
            int resLen = 0;

            int l, r;

            for (int i = 0; i < n; i++)
            {
                // ! odd length

                l = r = i;

                while (l >= 0 && r < n && s[l] == s[r])
                {
                    if (r - l + 1 > resLen)
                    {
                        res = s.substr(l, r - l + 1);
                        resLen = r - l + 1;
                    }

                    l--;
                    r++;
                }

                // ! even length

                l = i, r = i + 1;
                while (l >= 0 && r < n && s[l] == s[r])
                {
                    if (r - l + 1 > resLen)
                    {
                        res = s.substr(l, r - l + 1);
                        resLen = r - l + 1;
                    }

                    l--;
                    r++;
                }
            }

            return res;
        }
        */
};
// @lc code=end
