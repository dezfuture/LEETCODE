/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution
{
public:
    void reverse(vector<int> &v, int i, int j)
    {
        while (i < j)
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }

    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return;
        }

        int i = nums.size() - 2;

        while (i > 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }

        if (i > 0)
        {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i])
            {
                j--;
            }

            swap(nums[j], nums[i]);
        }

        reverse(nums, i + 1, nums.size() - 1);
    }
};
// @lc code=end
