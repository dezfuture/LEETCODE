/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int res = 0;
        stack<pair<int, int>> s;
        int n = speed.size();

        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++)
        {
            v[i] = {position[i], speed[i]};
        }

        sort(v.begin(), v.end(), greater<pair<int, int>>());

        for (auto &it : v)
        {
            if (!s.empty() && (double)(target - s.top().first) / s.top().second >= (double)(target - it.first) / it.second)
            {
                continue;
            }

            s.push(it);
        }

        return s.size();
    }
};
// @lc code=end
