/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int postfixSum = accumulate(nums.begin(), nums.end(), 0);
        int prefixSum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            postfixSum -= nums[i];
            if (prefixSum == postfixSum)
            {
                return i;
            }

            prefixSum += nums[i];
        }

        return -1;
    }
};
// @lc code=end
