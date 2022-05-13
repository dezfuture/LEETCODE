/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &prices)
    {
        int n = prices.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (prices[i] != 0)
            {
                prices[j++] = prices[i];
            }
        }

        while (j < n)
        {
            prices[j++] = 0;
        }
    }
};
// @lc code=end
