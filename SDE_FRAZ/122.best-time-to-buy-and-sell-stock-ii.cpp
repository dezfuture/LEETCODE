/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        int minP = prices[0];
        int n = prices.size();

        for (int i = 1; i < n; i++)
        {
            res += max(0, prices[i] - minP);
            minP = prices[i];
        }

        return res;
    }
};
// @lc code=end
