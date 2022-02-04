/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution
{
public:
    // DFS approach
    /*
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        stack<int> dfs;
        unordered_set<int> s = {0};
        dfs.push(0);

        while (!dfs.empty())
        {
            int i = dfs.top();
            dfs.pop();
            for (auto j : rooms[i])
            {
                if (s.count(j) == 0)
                {
                    dfs.push(j);
                    s.insert(j);
                    if (rooms.size() == s.size())
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    */

    // BFS approach
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<int> adj[n];
        for (int i = 0; i < rooms.size(); i++)
        {
            for (int j = 0; j < rooms[i].size(); j++)
            {
                adj[i].push_back(rooms[i][j]);
            }
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        int j = 0;
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            for (int i = 0; i < adj[t].size(); i++)
            {
                if (visited[adj[t][i]] == false)
                    q.push(adj[t][i]);
                visited[adj[t][i]] = true;
            }
            j++;
            if (j == n)
                return true;
        }
        return false;
    }
};
// @lc code=end
