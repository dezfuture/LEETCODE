/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int res = 0;
        vector<int> dir({-1, 0, 1, 0, -1});

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int ans = 1;
                    grid[i][j] = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while (!q.empty())
                    {
                        auto hell = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++)
                        {
                            int new_X = hell.first + dir[k];
                            int new_y = hell.second + dir[k + 1];

                            if (new_X >= 0 && new_X < m && new_y >= 0 && new_y < n && grid[new_X][new_y] == 1)
                            {
                                grid[new_X][new_y] = 0;
                                ans++;
                                q.push({new_X, new_y});
                            }
                        }
                    }

                    res = max(ans, res);
                }
            }
        }

        return res;
    }

    //     int maxAreaOfIsland(vector<vector<int>> &grid)
    //     {
    //         int m = grid.size();
    //         int n = grid[0].size();

    //         int res = 0;
    //         for (int i = 0; i < m; i++)
    //         {
    //             for (int j = 0; j < n; j++)
    //             {
    //                 if (grid[i][j] == 1)
    //                 {
    //                     res = max(res, dfs(grid, i, j));
    //                 }
    //             }
    //         }

    //         return res;
    //     }

    // private:
    //     int dfs(vector<vector<int>> &grid, int row, int col)
    //     {
    //         int m = grid.size();
    //         int n = grid[0].size();

    //         int ans = 1;

    //         grid[row][col] = 2;

    //         vector<int> dir({-1, 0, 1, 0, -1});

    //         for (int i = 0; i < 4; i++)
    //         {

    //             int r = row + dir[i];
    //             int c = col + dir[i + 1];

    //             if (r >= 0 && r < m && c >= 0 && c < m && grid[r][c] == 1)
    //             {
    //                 ans += dfs(grid, r, c);
    //             }
    //         }

    //         return ans;
    //     }
};
// @lc code=end
