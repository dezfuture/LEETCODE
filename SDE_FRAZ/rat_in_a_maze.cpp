//  ! gfg problem

class Solution
{
public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> res;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (m[0][0] == 1)
            solve(0, 0, m, n, res, "", vis);

        return res;
    }

private:
    void solve(int i, int j, vector<vector<int>> &m, int n, vector<string> &res, string move, vector<vector<int>> &vis)
    {
        if (i == n - 1 && j == n - 1)
        {
            res.push_back(move);
            return;
        }

        // ? downward

        if (i + 1 < n && !vis[i + 1][j] && m[i + 1][j] == 1)
        {
            vis[i][j] = 1;
            solve(i + 1, j, m, n, res, move + 'D', vis);
            vis[i][j] = 0;
        }

        // ? left

        if (j - 1 >= 0 && !vis[i][j - 1] && m[i][j - 1] == 1)
        {
            vis[i][j] = 1;
            solve(i, j - 1, m, n, res, move + 'L', vis);
            vis[i][j] = 0;
        }

        // ? right

        if (j + 1 < n && !vis[i][j + 1] && m[i][j + 1] == 1)
        {
            vis[i][j] = 1;
            solve(i, j + 1, m, n, res, move + 'R', vis);
            vis[i][j] = 0;
        }

        // ? up

        if (i - 1 >= 0 && !vis[i - 1][j] && m[i - 1][j] == 1)
        {
            vis[i][j] = 1;
            solve(i - 1, j, m, n, res, move + 'U', vis);
            vis[i][j] = 0;
        }
    }
};
