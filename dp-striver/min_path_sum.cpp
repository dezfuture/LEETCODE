// ? space optimization

#include <bits/stdc++.h>

using namespace std;

int minSumPath(int n, int m, vector<vector<int>> &matrix)
{
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                temp[j] = matrix[i][j];
            else
            {

                int up = matrix[i][j];
                if (i > 0)
                    up += prev[j];
                else
                    up += 1e9;

                int left = matrix[i][j];
                if (j > 0)
                    left += temp[j - 1];
                else
                    left += 1e9;

                temp[j] = min(up, left);
            }
        }
        prev = temp;
    }

    return prev[m - 1];
}

int main()
{

    vector<vector<int>> matrix{{5, 9, 6},
                               {11, 5, 2}};

    int n = matrix.size();
    int m = matrix[0].size();

    cout << minSumPath(n, m, matrix);
}

// ^ striver memoization

int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
    {
        return grid[0][0];
    }

    if (row < 0 || col < 0)
    {
        return 0;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int up = grid[row][col] + solve(row - 1, col, grid, dp);
    int left = grid[row][col] + solve(row, col - 1, grid, dp);

    return dp[row][col] = up + left;
}

int minSumPath(vector<vector<int>> &grid)
{

    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return solve(m - 1, n - 1, grid, dp);
}

//  ! aditya verma method dp in tabulation form

int minSumPath(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, grid[0][0]));

    for (int i = 1; i < m; i++)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; j++)
    {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return dp[m - 1][n - 1];
}