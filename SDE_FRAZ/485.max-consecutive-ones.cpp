/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int res = 0, count = 0;
        for (auto x : nums)
        {
            if (x == 1)
            {
                count++;
                res = max(count, res);
            }
            else
            {
                count = 0;
            }
        }
        return res;
    }
};
// @lc code=end
