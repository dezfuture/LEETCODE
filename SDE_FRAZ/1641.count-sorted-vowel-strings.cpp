/*
 * @lc app=leetcode id=1641 lang=cpp
 *
 * [1641] Count Sorted Vowel Strings
 */

// @lc code=start

class Solution
{
public:
    int countVowelStrings(int n)
    {
        vector<int> dp(5, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 3; j >= 0; j--)
            {
                dp[j] += dp[j + 1];
            }
        }

        return dp[0];
        }
};

/*  // ? Recursion Solution


class Solution
{
public:
    int countVowelStrings(int n)
    {
        return count(n, 'a');
    }

private:
    int count(int n, char ch)
    {
        string s = "aeiou";

        if (n == 1)
        {
            int ans = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] - 'a' >= ch - 'a')
                {
                    ans++;
                }
            }

            return ans;
        }

        int ans = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] - 'a' >= ch - 'a')
            {
                ans += count(n - 1, s[i]);
            }
        }

        return ans;
    }
};

*/
// @lc code=end
