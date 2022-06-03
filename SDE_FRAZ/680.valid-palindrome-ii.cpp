/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int n = s.size();
        int low = 0, high = n - 1;
        int count = 0;
        return solve(s, low, high, count);
    }

private:
    bool solve(string &s, int low, int high, int count)
    {
        if (count > 1)
        {
            return false;
        }

        while (low < high)
        {
            if (s[low] == s[high])
            {
                low++;
                high--;
            }
            else
            {
                return solve(s, low + 1, high, count + 1) || solve(s, low, high - 1, count + 1);
            }
        }

        return true;
    }
};
// @lc code=end
