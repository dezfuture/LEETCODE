/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {

        // ? pair the index and height
        stack<pair<int, int>> s;
        int maxArea = 0;

        int n = heights.size();

        for (int i = 0; i < n; i++)
        {
            int start = i;

            while (!s.empty() && s.top().second > heights[i])
            {
                int index = s.top().first;
                int height = s.top().second;
                s.pop();
                maxArea = max(maxArea, height * (i - index));

                start = index;
            }

            s.push({start, heights[i]});
        }

        while (!s.empty())
        {
            int index = s.top().first;
            int height = s.top().second;
            s.pop();

            maxArea = max(maxArea, height * (n - index));
        }

        return maxArea;
    }
};
// @lc code=end
