/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;

        std::sort(intervals.begin(), intervals.end());

        int s = intervals[0][0];
        int e = intervals[0][1];

        int n = intervals.size();

        for (int i = 1; i < n; i++)
        {
            if (e >= intervals[i][0])
            {
                e = max(e, intervals[i][1]);
            }
            else
            {
                res.push_back({s, e});
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }

        res.push_back({s, e});

        return res;
    }
};
// @lc code=end
