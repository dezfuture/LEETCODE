/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> res;
        sort(nums.begin(), nums.end());
        solve(0, nums, res, ans);
        return ans;
    }

private:
    void solve(int idx, vector<int> &nums, vector<int> &res, vector<vector<int>> &ans)
    {
        ans.push_back(res);

        for (int i = idx; i < nums.size(); i++)
        {
            if (i > idx && nums[i] == nums[i - 1])
            {
                continue;
            }

            res.push_back(nums[i]);
            solve(i + 1, nums, res, ans);
            res.pop_back();
        }
    }
};
// @lc code=end
