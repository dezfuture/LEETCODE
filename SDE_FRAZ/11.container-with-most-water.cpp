/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int water = 0;
        int i = 0, j = height.size() - 1;

        while (i < j)
        {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);

            while (height[i] <= h && i < j)
            {
                i++;
            }

            while (height[j] <= h && i < j)
            {
                j--;
            }
        }

        return water;
    }
};
// @lc code=end
