#include <bits/stdc++.h>
using namespace std;

// logic over here is :

/*

*As we know that topological sort only applies to DAG and if the count in the topological sort is
*not equal to the number of nodes then we can say that there is a cycle otherwise no cycle exists.

*/

class Solution
{
public:
    bool isCyclic(int N, vector<int> adj[])
    {
        queue<int> q;
        vector<int> indegree(N, 0);
        for (int i = 0; i < N; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if (cnt == N)
            return false;
        return true;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}