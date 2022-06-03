/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;
        int i = 0;
        int n = nums.size();

        while (i < n)
        {
            int temp = nums[i] - 1;
            if (nums[i] != nums[temp])
            {
                swap(nums[i], nums[temp]);
            }
            else
            {
                i++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};
// @lc code=end
