/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 */

// @lc code=start
class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int n = time.size();
        unordered_map<int, int> m;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            time[i] %= 60;
            res += (time[i] == 0) ? m[0] : m[60 - time[i]];

            m[time[i]]++;
        }

        return res;
    }
};
// @lc code=end
