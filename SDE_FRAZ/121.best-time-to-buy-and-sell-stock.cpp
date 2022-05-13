/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxP = 0, minP = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            maxP = max(maxP, prices[i] - minP);
            minP = min(minP, prices[i]);
        }

        return maxP;
    }
};
// @lc code=end
