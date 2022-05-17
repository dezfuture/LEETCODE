/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution
{
public:
    // ? O(n) time and O(1) space

    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        int start = 1, end = 1;
        vector<int> res(n, 1);

        for (int i = 0; i < n; i++)
        {
            res[i] *= start;
            start *= nums[i];
            res[n - i - 1] *= end;
            end *= nums[n - i - 1];
        }

        return res;
    }

    // ? O(n) time and O(n) space complexity
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> start(n), end(n);

        start[0] = 1;
        end[0] = 1;

        for (int i = 1; i < n; i++)
        {
            start[i] = start[i - 1] * nums[i - 1];
            end[i] = end[i - 1] * nums[n - i];
        }

        vector<int> res(n);

        for (int i = 0; i < n; i++)
        {
            res[i] = start[i] * end[n - i - 1];
        }

        return res;
    }
};
// @lc code=end
