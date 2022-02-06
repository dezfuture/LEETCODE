/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start

// Union find and path compression - O(N*log(N))

class Solution
{
public:
    int parent[10005];
    int rank[10005];

    int find(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void unionn(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a != b)
        {
            if (rank[a] < rank[b])
            {
                parent[a] = b;
            }
            else if (rank[a] > rank[b])
            {
                parent[b] = a;
            }
            else
            {
                parent[a] = b;
                rank[b] += 1;
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }

        vector<int> ans;

        for (auto hell : edges)
        {
            int a = find(hell[0]);
            int b = find(hell[1]);

            if (a != b)
            {
                unionn(a, b);
            }
            else
            {
                ans = hell;
                break;
            }
        }
        return ans;
    }
};

// Single dfs traversal - O(n)

// class Solution
// {
// public:
//     unordered_set<int> cycle;
//     int cycleStart = -1;

//     void dfs(vector<vector<int>> &graph, vector<bool> &visited, int curr, int parent = -1)
//     {
//         if (visited[curr])
//         {
//             cycleStart = curr;
//             return;
//         }

//         visited[curr] = true;

//         for (auto child : graph[curr])
//         {

//             if (child == parent)
//             {
//                 continue;
//             }
//             if (cycle.empty())
//             {
//                 dfs(graph, visited, child, curr);
//             }
//             if (cycleStart != -1)
//             {
//                 cycle.insert(curr);
//             }
//             if (curr == cycleStart)
//             {
//                 cycleStart = -1;
//                 return;
//             }
//         }
//     }

//     vector<int> findRedundantConnection(vector<vector<int>> &edges)
//     {
//         int n = edges.size();

//         vector<vector<int>> graph(n + 1);
//         vector<bool> visited(n + 1, false);

//         for (auto &e : edges)
//         {
//             graph[e[0]].push_back(e[1]);
//             graph[e[1]].push_back(e[0]);
//         }

//         dfs(graph, visited, 1);

//         for (int i = n - 1; i >= 0; i--)
//         {
//             if (cycle.count(edges[i][0]) && cycle.count(edges[i][1]))
//             {
//                 return edges[i];
//             }
//         }

//         return {};
//     }
// };

// Multiple dfs traversal - O(n^2)

// class Solution
// {
// public:
//     vector<int> findRedundantConnection(vector<vector<int>> &edges)
//     {
//         int n = edges.size();
//         vector<vector<int>> graph(n + 1);

//         vector<bool> visited(n + 1);
//         // we go through each edge one by one and when we find a cycle we know that particular edge is the one
//         // due to which the cycle is made
//         for (auto e : edges)
//         {
//             fill(visited.begin(), visited.end(), false);

//             graph[e[0]].push_back(e[1]);
//             graph[e[1]].push_back(e[0]);
//             if (dfs(graph, visited, e[0]))
//             {
//                 return e;
//             }
//         }

//         return {};
//     }

// private:
//     bool dfs(vector<vector<int>> &graph, vector<bool> &visited, int curr, int parent = -1)
//     {
//         if (visited[curr])
//         {
//             return true;
//         }

//         visited[curr] = true;

//         for (auto child : graph[curr])
//         {
//             if (child != parent && dfs(graph, visited, child, curr))
//             {
//                 return true;
//             }
//         }

//         // no cycle found
//         return false;
//     }
// };
// @lc code=end
