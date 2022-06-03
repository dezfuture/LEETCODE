/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        // int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        vector<int> prefix(n, 0);

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += cardPoints[i];
            prefix[i] = sum;
        }
        if (n == k)
        {
            return sum;
        }

        int res = sum - prefix[n - k - 1];

        for (int i = 1; i < k + 1; i++)
        {
            int j = i + (n - k) - 1;
            int temp = prefix[j] - prefix[i - 1];
            res = max(res, sum - temp);
        }

        return res;
    }
};
// @lc code=end
