/*
 * @lc app=leetcode id=690 lang=cpp
 *
 * [690] Employee Importance
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        vector<int> temp;

        int res = 0;

        for (int i = 0; i < employees.size(); i++)
        {
            if (id == employees[i]->id)
            {
                res += employees[i]->importance;
                temp = employees[i]->subordinates;

                break;
            }
        }

        for (int i = 0; i < temp.size(); i++)
        {
            res += getImportance(employees, temp[i]);
        }

        return res;
    }

    // BFS Solution

    // int getImportance(vector<Employee *> employees, int id)
    // {
    //     unordered_map<int, Employee *> m;

    //     int res = 0;

    //     for (int i = 0; i < employees.size(); i++)
    //     {
    //         m[employees[i]->id] = employees[i];
    //     }

    //     queue<int> q;
    //     q.push(id);

    //     while (!q.empty())
    //     {
    //         Employee *curr;

    //         int hell = q.front();
    //         q.pop();

    //         curr = m[hell];

    //         res += curr->importance;

    //         vector<int> child = curr->subordinates;

    //         for (int i = 0; i < child.size(); i++)
    //         {
    //             q.push(child[i]);
    //         }
    //     }

    //     return res;
    // }
};
// @lc code=end
