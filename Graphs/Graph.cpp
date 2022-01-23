// Adjacency List

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // declare the adjacent matrix
    vector<int> adj[n + 1];

    // if its a weighted graph then take pair<int, int> instead of int

    // take edges as input
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}

// Adjacency Matrix (for small values of n)

/*

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // declare the adjacent matrix
    int adj[n+1][n+1];

    // take edges as input
    for(int i = 0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}

*/