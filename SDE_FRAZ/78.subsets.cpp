/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        int subsett = 1 << n;

        for (int mask = 0; mask < subset; mask++)
        {
            vector<int> res;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    res.push_back(nums[i]);
                }
            }

            ans.push_back(res);
        }

        return ans;
    }
};
// @lc code=end
