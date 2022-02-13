/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<vector<int>> &stones, int u, vector<int> &visited)
    {
        visited[u] = 1;

        for (int v = 0; v < stones.size(); v++)
        {
            if (v != u && visited[v] == 0 && (stones[v][0] == stones[u][0] || stones[u][1] == stones[v][1]))
            {
                dfs(stones, v, visited);
            }
        }
    }

    int removeStones(vector<vector<int>> &stones)
    {
        int isConnected = 0;

        vector<int> visited(stones.size() + 1, 0);

        for (int i = 0; i < stones.size(); i++)
        {
            if (visited[i] == 0)
            {
                dfs(stones, i, visited);
                isConnected++;
            }
        }

        return stones.size() - isConnected;
    }
};
// @lc code=end
