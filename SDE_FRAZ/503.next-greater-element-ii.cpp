/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution
{
public:
    // ? modifying the orignal vector

    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> s;

        vector<int> res(n, -1);

        for (int i = n - 2; i >= 0; i--)
        {
            s.push(nums[i]);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && nums[i] >= s.top())
            {
                s.pop();
            }

            if (!s.empty())
            {
                res[i] = s.top();
            }

            s.push(nums[i]);
        }

        return res;
    }
};
// @lc code=end
