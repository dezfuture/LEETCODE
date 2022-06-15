/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start

// ? backtracking

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        solve(0, nums, ans);

        return ans;
    }

private:
    void solve(int idx, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[idx], nums[i]);
            solve(idx + 1, nums, ans);
            swap(nums[idx], nums[i]);
        }
    }
};

// ? recursion solution

// class Solution
// {
// public:
//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         vector<vector<int>> ans;
//         vector<int> res;
//         vector<int> hash(nums.size(), 0);

//         solve(nums, res, hash, ans);

//         return ans;
//     }

// private:
//     void solve(vector<int> &nums, vector<int> &res, vector<int> &hash, vector<vector<int>> &ans)
//     {
//         if (nums.size() == res.size())
//         {
//             ans.push_back(res);
//             return;
//         }

//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (!hash[i])
//             {
//                 res.push_back(nums[i]);
//                 hash[i] = 1;
//                 solve(nums, res, hash, ans);
//                 hash[i] = 0;
//                 res.pop_back();
//             }
//         }
//     }
// };
// @lc code=end
