/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start

// BFS Solution

class Solution
{

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<int> vec({-1, 0, 1, 0, -1});

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while (!q.empty())
                    {
                        auto curr = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++)
                        {
                            int r = curr.first + vec[k];
                            int c = curr.second + vec[k + 1];

                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1')
                            {
                                grid[r][c] = '0';
                                q.push({r, c});
                            }
                        }
                    }
                }
            }
        }

        return res;
    }
};

// !DFS solution

// class Solution
// {
// public:
//     int numIslands(vector<vector<char>> &grid)
//     {
//         int res = 0;
//         int m = grid.size();
//         int n = grid[0].size();

//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (grid[i][j] == '1')
//                 {
//                     res++;
//                     solve(grid, i, j);
//                 }
//             }
//         }

//         return res;
//     }

// private:
//     void solve(vector<vector<char>> &grid, int r, int c)
//     {
//         int m = grid.size();
//         int n = grid[0].size();
//         if (r < 0 || r == m || c < 0 || c == n || grid[r][c] == '0')
//         {
//             return;
//         }

//         grid[r][c] = '0';

//         solve(grid, r + 1, c);
//         solve(grid, r - 1, c);
//         solve(grid, r, c + 1);
//         solve(grid, r, c - 1);
//     }
// };
// @lc code=end
