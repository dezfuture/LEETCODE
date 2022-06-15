/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution
{
public:
    // ! the approach is not very much intuitive but try dry run on first base case

    string minWindow(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        unordered_map<char, int> hell;

        for (auto x : t)
        {
            hell[x]++;
        }

        int low = 0, count = 0;
        int min_start = 0, min_len = 1e8;

        for (int high = 0; high < n; high++)
        {
            if (hell[s[high]] > 0)
            {
                count++;
            }

            hell[s[high]]--;

            if (count == m)
            {
                while (low < high && hell[s[low]] < 0)
                {
                    hell[s[low]]++;
                    low++;
                }

                if (min_len > (high - low + 1))
                {
                    min_start = low;
                    min_len = high - low + 1;
                }
            }
        }

        if (min_len == 1e8)
        {
            return "";
        }

        return s.substr(min_start, min_len);
    }
};
// @lc code=end
