/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> v;
        solve(0, target, candidates, res, v);
        return res;
    }

private:
    void solve(int idx, int target, vector<int> &candidates, vector<vector<int>> &res, vector<int> &v)
    {
        if (idx == candidates.size())
        {
            if (target == 0)
            {
                res.push_back(v);
            }

            return;
        }

        if (candidates[idx] <= target)
        {
            v.push_back(candidates[idx]);
            solve(idx, target - candidates[idx], candidates, res, v);
            v.pop_back();
        }

        solve(idx + 1, target, candidates, res, v);
    }
};
// @lc code=end
