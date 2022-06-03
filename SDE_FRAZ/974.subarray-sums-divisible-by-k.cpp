/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0;
        int ans = 0;
        int rem = 0;

        for (auto it : nums)
        {
            sum += it;
            rem = sum % k;
            if (rem < 0)
            {
                rem += k;
            }

            if (m[rem])
            {
                ans += m[rem];
                m[rem] += 1;
            }
            else
            {
                m[rem] = 1;
            }
        }

        return ans;
    }
};
// @lc code=end
