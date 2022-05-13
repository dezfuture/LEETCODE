/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start

// !BFS ( Topological Sort) Solution

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        queue<int> zeroDegree;
        vector<int> res;
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
                res.push_back(i);
            }
        }

        while (!zeroDegree.empty())
        {
            int node = zeroDegree.front();
            zeroDegree.pop();

            for (int i = 0; i < graph[node].size(); i++)
            {
                int hell = graph[node][i];
                degree[hell]--;
                if (degree[hell] == 0)
                {
                    zeroDegree.push(hell);
                    res.push_back(hell);
                }
            }
        }

        if (res.size() != numCourses)
        {
            return vector<int>();
        }

        return res;
    }
};
// @lc code=end
