/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();

        int end = n - 1, start = 0;

        vector<int> res(n);
        int pos = n - 1;

        for (int i = 0; i < n; i++)
        {
            if (abs(nums[start]) < abs(nums[end]))
            {
                res[pos--] = nums[end] * nums[end];
                end--;
            }
            else
            {
                res[pos--] = nums[start] * nums[start];
                start++;
            }
        }

        return res;
    }
};
// @lc code=end
