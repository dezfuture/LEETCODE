/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        unordered_set<char> hell;
        int i = 0, j = 0, res = 0;

        while (j < n)
        {
            if (hell.find(s[j]) == hell.end())
            {
                hell.insert(s[j]);
                j++;
                res = max(res, j - i);
            }
            else
            {
                hell.erase(s[i]);
                i++;
            }
        }

        return res;
    }
};
// @lc code=end
