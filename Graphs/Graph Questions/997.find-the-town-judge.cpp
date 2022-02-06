/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution
{
public:
    // Classic indegree and outdegree problem

    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> a(n + 1, 0), b(n + 1, 0);
        if (trust.empty() && n == 1)
        {
            return 1;
        }

        for (auto val : trust)
        {
            a[val[0]]++;
            b[val[1]]++;
        }

        for (int i = 0; i < n + 1; i++)
        {
            if (a[i] == 0 && b[i] == n - 1)
            {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end
