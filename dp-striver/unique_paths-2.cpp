// * tabulation solution

int mazeObstacles(int n, int m, vector<vector<int>> &matrix)
{

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int mod = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > 0 && j > 0 && matrix[i][j] == -1)
            {
                dp[i][j] = 0;
            }

            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }

            int up = 0, left = 0;

            if (i > 0)
            {
                up = dp[i - 1][j];
            }

            if (j > 0)
            {
                left = dp[i][j - 1];
            }

            dp[i][j] = up + left;
        }
    }

    return dp[n - 1][m - 1] % mod;
}

// ^ you can space optimize your solution using a vector instead of 2d array.