/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> res;

        solve(0, target, candidates, ans, res);

        return ans;
    }

private:
    void solve(int idx, int target, vector<int> &v, vector<vector<int>> &ans, vector<int> &res)
    {
        if (target == 0)
        {
            ans.push_back(res);
            return;
        }

        for (int i = idx; i < v.size(); i++)
        {
            if (i > idx && v[i] == v[i - 1])
            {
                continue;
            }

            if (v[i] > target)
            {
                break;
            }

            res.push_back(v[i]);
            solve(i + 1, target - v[i], v, ans, res);
            res.pop_back();
        }
    }
};
// @lc code=end
