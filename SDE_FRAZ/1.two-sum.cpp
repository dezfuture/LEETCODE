/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<int> v;
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            if (m.find(target - nums[i]) != m.end())
            {
                v.push_back(m[target - nums[i]]);
                v.push_back(i);
                return v;
            }
            else
            {
                m[nums[i]] = i;
            }
        }

        return v;
    }
};
// @lc code=end
