/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_map<int, int> a;
        for (int i : nums)
            a[i]++;
        int ans = 0;
        for (auto x : a)
        {
            if (k == 0)
            {
                if (x.second > 1)
                    ans++;
            }
            else if (a.find(x.first + k) != a.end())
                ans++;
        }

        return ans;
    }
};
// @lc code=end
