/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.size();
        int m = p.size();

        vector<int> temp1(26, 0), temp2(26, 0);

        for (int i = 0; i < m; i++)
        {
            temp2[p[i] - 'a']++;
        }

        int high = 0, low = 0;
        vector<int> res;
        while (high < n)
        {
            temp1[s[high] - 'a']++;

            if (high - low + 1 == m)
            {
                if (solve(temp1, temp2))
                {
                    res.push_back(low);
                    // low++;
                }
            }

            if (high - low + 1 < m)
            {
                high++;
            }
            else
            {
                temp1[s[low] - 'a']--;
                low++;
                high++;
            }
        }
        return res;
    }

private:
    bool solve(vector<int> temp, vector<int> hell)
    {
        for (int i = 0; i < 26; i++)
        {
            if (temp[i] != hell[i])
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
