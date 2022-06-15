/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 */

// @lc code=start
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++)
        {
            for (auto j : nums[i])
            {
                v.push_back({j, i});
            }
        }

        sort(v.begin(), v.end());
        int k = nums.size();
        vector<int> ans;
        map<int, int> m;
        int j = 0;

        int minn = 1e9;
        int total = 0;

        for (int i = 0; i < v.size(); i++)
        {
            m[v[i].second++];
            if (m[v[i].second] == 1)
            {
                total++;
            }
        }
    }
};
// @lc code=end
