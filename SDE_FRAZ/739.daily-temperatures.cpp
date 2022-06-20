/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<pair<int, int>> s;
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && temperatures[i] > s.top().second)
            {
                int index = s.top().first;
                int t = s.top().second;

                res[index] = i - index;
            }

            s.push({i, temperatures[i]});
        }

        return res;
    }
};
// @lc code=end
