/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        int sum = 0;
        int ans = 0;

        m[sum] = 1;

        for (auto it : nums)
        {
            sum += it;
            int find = sum - k;
            if (m.find(find) != m.end())
            {
                ans += m[find];
            }

            m[sum]++;
        }

        return ans;
    }
};
// @lc code=end
