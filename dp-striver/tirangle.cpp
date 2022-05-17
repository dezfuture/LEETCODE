#include <bits/stdc++.h>
using namespace std;

// * space optimization

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<int> front(n, 0), cur(n, 0);

    for (int j = 0; j < n; j++)
    {
        front[j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {

            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];

            cur[j] = min(down, diagonal);
        }
        front = cur;
    }

    return front[0];
}

// * tabulation solution

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagnol = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, diagnol);
        }
    }

    return dp[0][0];
}

//  ^ memoization

int solve(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    if (i == n - 1)
    {
        return dp[i][j];
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int down = triangle[i][j] + solve(i + 1, j, triangle, n, dp);
    int right = triangle[i][j] + solve(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(down, right);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // starting at the first position
    return solve(0, 0, triangle, n, dp);
}

//  TODO  --- >  the recurrence relation is

f(i, j)
{

    if (i == n - 1)
    {
        return a[n - 1][j];
    }

    down = a[i][j] + f(i + 1, j);
    right = a[i][j] + f(i + 1, j + 1);

    return min(down, right);
}

//  ~ time complexity => pow(2, (1 + 2 + ... + (n+1)))