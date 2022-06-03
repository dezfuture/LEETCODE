/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution
{
public:
    //  ! greedy

    int jump(vector<int> &nums)
    {
        int res = 0;
        int left = 0, right = 0;

        while (right < nums.size() - 1)
        {
            int farthest = 0;
            for (int i = left; i < right + 1; i++)
            {
                farthest = max(farthest, i + nums[i]);
            }

            left = right + 1;
            right = farthest;
            res++;
        }

        return res;
    }

    // ? tabulation

    // int jump(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     vector<int> dp(n + 1, 1e8);

    //     dp[0] = 0;

    //     for (int i = 0; i < n - 1; i++)
    //     {
    //         int jump = nums[i];
    //         for (int j = i + 1; j <= min(i + jump, n - 1); j++)
    //         {
    //             dp[j] = min(dp[j], dp[i] + 1);
    //         }
    //     }

    //     return dp[n - 1];
    // }

    // ? recursive solution

    // int solve(vector<int> &nums, int pos)
    // {
    //     int n = nums.size() - 1;
    //     if (pos >= n)
    //     {
    //         return 0;
    //     }

    //     int minn = 1e8;

    //     for (int jump = 1; jump <= nums[pos]; jump++)
    //     {
    //         minn = min(minn, 1 + solve(nums, pos + jump));
    //     }

    //     return minn;
    // }
};
// @lc code=end
