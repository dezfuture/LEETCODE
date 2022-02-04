/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start

//  BACKTRACKING + DFS

class Solution
{

    // BFS solution
    // using a queue of vector
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> result;

        int n = graph.size();

        int start = 0, end = n;

        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            for (auto temp : graph[i])
            {
                adj[i].push_back(temp);
            }
        }

        queue<vector<int>> q;
        q.push({0});
        vector<int> path;

        while (!q.empty())
        {
            path = q.front();
            q.pop();
            if (path.back() == n - 1)
            {
                result.push_back(path);
            }

            for (auto it : adj[path.back()])
            {
                vector<int> temp;
                temp.push_back(it);
                q.push(temp);
            }
        }

        return res;
    }

    // DFS solution

    /*
    public:
        vector<vector<int>> res;

        vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
        {
            int end = graph.size() - 1;
            vector<int> path;

            dfs(graph, path, 0, end);

            return res;
        }

    private:
        void dfs(vector<vector<int>> &graph, vector<int> &path, int start, int end)
        {
            if (graph[start].size() == 0 || start == end)
            {
                path.push_back(start);
                if (end == start)
                {
                    vector<int> temp = path;
                    res.push_back(temp);
                }

                path.pop_back();
            }

            path.push_back(start);
            for (auto i : graph[start])
            {
                dfs(graph, path, i, end);
            }
            path.pop_back();
        }
        */
};
// @lc code=end
