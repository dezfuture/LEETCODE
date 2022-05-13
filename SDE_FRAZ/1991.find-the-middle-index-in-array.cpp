/*
 * @lc app=leetcode id=1991 lang=cpp
 *
 * [1991] Find the Middle Index in Array
 */

// @lc code=start
class Solution
{
public:
    // can be done using cummulative sum

    int findMiddleIndex(vector<int> &nums)
    {
        int postfixSum = accumulate(nums.begin(), nums.end(), 0);

        int prefixSum = 0;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            postfixSum -= nums[i];

            if (postfixSum == prefixSum)
            {
                return i;
            }

            prefixSum += nums[i];
        }

        return -1;
    }
};
// @lc code=end
