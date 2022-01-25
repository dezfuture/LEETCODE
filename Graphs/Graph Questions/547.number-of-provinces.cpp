/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 *
 * https://leetcode.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (62.45%)
 * Likes:    4501
 * Dislikes: 219
 * Total Accepted:    401K
 * Total Submissions: 641.9K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * There are n cities. Some of them are connected, while some are not. If city
 * a is connected directly with city b, and city b is connected directly with
 * city c, then city a is connected indirectly with city c.
 *
 * A province is a group of directly or indirectly connected cities and no
 * other cities outside of the group.
 *
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
 * i^th city and the j^th city are directly connected, and isConnected[i][j] =
 * 0 otherwise.
 *
 * Return the total number of provinces.
 *
 *
 * Example 1:
 *
 *
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 200
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] is 1 or 0.
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int res = 0;
        vector<int> v(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0)
            {
                res++;
                dfs(i, isConnected, v);
            }
        }

        return res;
    }

private:
    void dfs(int node, vector<vector<int>> &isConnected, vector<int> &v)
    {
        if (v[node] == 1)
        {
            return;
        }

        v[node] = 1;

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (i != node && isConnected[node][i] == 1)
            {
                dfs(i, isConnected, v);
            }
        }
    }
};
// @lc code=end
