// !BFS Solution (TOPOLOGICAL SORTING)

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        queue<int> zeroDegree;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }

        for (int i = 0; i < degree.size(); i++)
        {
            if (degree[i] == 0)
            {
                zeroDegree.push(i);
                numCourses--;
            }
        }

        while (!zeroDegree.empty())
        {
            int node = zeroDegree.front();
            zeroDegree.pop();
            for (int i = 0; i < graph[node].size(); i++)
            {
                int connectedNode = graph[node][i];
                degree[connectedNode]--;
                if (degree[connectedNode] == 0)
                {
                    zeroDegree.push(connectedNode);
                    numCourses--;
                }
            }
        }

        return numCourses == 0;
    }
};

// !DFS Solution

// class Solution
// {
// public:
//     vector<int> visited;
//     unordered_map<int, vector<int>> hash;
//     bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
//     {
//         for (int i = 0; i < numCourses; i++)
//         {
//             visited.push_back(0);
//             hash[i] = {};
//         }

//         for (auto i : prerequisites)
//         {
//             hash[i[0]].push_back(i[1]);
//         }

//         for (int i = 0; i < numCourses; i++)
//         {
//             if (!solve(i))
//             {
//                 return false;
//             }
//         }

//         return true;
//     }

// private:
//     bool solve(int n)
//     {
//         if (visited[n] == 1)
//         {
//             return false;
//         }
//         if (visited[n] == 2)
//         {
//             return true;
//         }
//         else
//         {
//             visited[n] = 1;
//             for (auto j : hash[n])
//             {
//                 if (!solve(j))
//                 {
//                     return false;
//                 }
//             }

//             visited[n] = 2;
//             return true;
//         }
//     }
// };