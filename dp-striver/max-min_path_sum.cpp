#include <bits/stdc++.h>
using namespace std;

// * memoization

int solve(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (j < 0 || j >= n)
    {
        return -1e9;
    }

    if (i == 0)
    {
        return matrix[0][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = matrix[i][j] + solve(i - 1, j, n, matrix, dp);
    int right = matrix[i][j] + solve(i - 1, j + 1, n, matrix, dp);
    int left = matrix[i][j] + solve(i - 1, j - 1, n, matrix, dp);

    return dp[i][j] = max({up, left, right});
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    int mxn = INT_MIN;

    // ? taking each box of the last row as starting point

    for (int j = 0; j < n; j++)
    {
        int ans = solve(n - 1, j, n, matrix, dp);

        mxn = max(mxn, ans);
    }

    return mxn;
}

// * tabulation

int getMaxPathSum(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initializing first row - base condition
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int up = matrix[i][j] + dp[i - 1][j];

            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0)
                leftDiagonal += dp[i - 1][j - 1];
            else
                leftDiagonal += -1e9;

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m)
                rightDiagonal += dp[i - 1][j + 1];
            else
                rightDiagonal += -1e9;

            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
        }
    }

    int maxi = INT_MIN;

    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, dp[n - 1][j]);
    }

    return maxi;
}

int main()
{

    vector<vector<int>> matrix{{1, 2, 10, 4},
                               {100, 3, 2, 1},
                               {1, 1, 20, 2},
                               {1, 2, 2, 1}};

    cout << getMaxPathSum(matrix);
}

// * space optimization

int getMaxPathSum(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m, 0), cur(m, 0);

    // Initializing first row - base condition
    for (int j = 0; j < m; j++)
    {
        prev[j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int up = matrix[i][j] + prev[j];

            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0)
                leftDiagonal += prev[j - 1];
            else
                leftDiagonal += -1e9;

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m)
                rightDiagonal += prev[j + 1];
            else
                rightDiagonal += -1e9;

            cur[j] = max(up, max(leftDiagonal, rightDiagonal));
        }

        prev = cur;
    }

    int maxi = INT_MIN;

    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, prev[j]);
    }

    return maxi;
}