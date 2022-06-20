/*
 * @lc app=leetcode id=1856 lang=cpp
 *
 * [1856] Maximum Subarray Min-Product
 */

// @lc code=start
class Solution
{
public:
    int maxSumMinProduct(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> sums(n + 1, 0);

        sums[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        int res = -1e9;
        stack<pair<int, int>> s;
        for (int i = 1; i < n + 1; i++)
        {
            int newStart = i;

            while (!s.empty() && s.top().second > nums[i - 1])
            {
                int start, val;
                start = s.top().first;
                val = s.top().second;
                s.pop();
                int total = sums[i] - sums[start];
                res = max(res, total * val);
                newStart = start;
            }

            s.push({newStart, nums[i - 1]});
        }
        int mod = (int)1e9 + 7;
        while (!s.empty())
        {
            int start, val;
            start = s.top().first;
            val = s.top().second;
            s.pop();
            int total = sums[n] - sums[start - 1];

            res = max(res, total * val);
        }

        return res % mod;
    }
};
// @lc code=end
