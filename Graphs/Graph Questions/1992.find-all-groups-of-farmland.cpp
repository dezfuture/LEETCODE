/*
 * @lc app=leetcode id=1992 lang=cpp
 *
 * [1992] Find All Groups of Farmland
 */

// @lc code=start

// !BFS Solution

class Solution
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> res;
        int m = land.size();
        int n = land[0].size();

        vector<int> dir({-1, 0, 1, 0, -1});

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (land[i][j] == 1)
                {
                    pair<int, int> p1 = {i, j}, p2 = p1;
                    queue<pair<int, int>> q;
                    land[i][j] = 0;
                    q.push({i, j});

                    while (!q.empty())
                    {
                        auto temp = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++)
                        {
                            int new_X = temp.first + dir[k];
                            int new_Y = temp.second + dir[k + 1];

                            if (new_X >= 0 && new_Y >= 0 && new_X < m && new_Y < n && land[new_X][new_Y] == 1)
                            {
                                land[new_X][new_Y] = 0;
                                q.push({new_X, new_Y});
                                p2 = {new_X, new_Y};
                            }
                        }
                    }

                    res.push_back({p1.first, p1.second, p2.first, p2.second});
                }
            }
        }
        return res;
    }
};

// !DFS Solution

/*
class Solution
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        int m = land.size();
        int n = land[0].size();

        vector<vector<int>> res;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (land[i][j] == 1)
                {
                    int x_min = 305, y_min = 305, x_max = -1, y_max = -1;
                    dfs(land, i, j, x_min, y_min, x_max, y_max);
                    vector<int> temp = {x_min, y_min, x_max, y_max};
                    res.push_back(temp);
                }
            }
        }

        return res;
    }

private:
    void dfs(vector<vector<int>> &land, int row, int col, int &x_min, int &y_min, int &x_max, int &y_max)
    {

        int m = land.size();
        int n = land[0].size();

        if (row < 0 || col < 0 || row >= m || col >= n || land[row][col] == 0)
        {
            return;
        }

        land[row][col] = 0;

        x_min = min(x_min, row);
        x_max = max(x_max, row);
        y_min = min(y_min, col);
        y_max = max(y_max, col);

        dfs(land, row + 1, col, x_min, y_min, x_max, y_max);
        dfs(land, row - 1, col, x_min, y_min, x_max, y_max);
        dfs(land, row, col + 1, x_min, y_min, x_max, y_max);
        dfs(land, row, col - 1, x_min, y_min, x_max, y_max);
    }
};

*/
// @lc code=end
