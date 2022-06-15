#include <bits/stdc++.h>

// ? memoization

int solve(int a[], int idx, int prev_idx, vector<vector<int>> &dp, int n)
{
    if (idx == n)
    {
        return 0;
    }

    if (dp[idx][prev_idx + 1] != -1)
    {
        return dp[idx][prev_idx + 1];
    }

    int len = 0 + solve(a, idx + 1, prev_idx, dp, n);

    if (prev_idx == -1 || a[idx] > a[prev_idx])
    {
        len = max(len, 1 + solve(a, idx + 1, idx, dp, n));
    }

    return dp[idx][prev_idx + 1] = len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return solve(arr, 0, -1, dp, n);
}

// ? tabulation

int longestIncreasingSubsequence(int a[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--)
        {
            int len = 0 + dp[idx + 1][prev_idx + 1];
            if (prev_idx == -1 || a[idx] > a[prev_idx])
            {
                len = max(len, 1 + dp[idx + 1][idx + 1]);
            }

            dp[idx][prev_idx + 1] = len;
        }
    }

    return dp[0][0];
}

// ? space optimization

int longestIncreasingSubsequence(int a[], int n)
{
    vector<int> curr(n + 1, 0), next(n + 1, 0);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int prev_idx = idx - 1; prev_idx >= -1; prev_idx--)
        {
            int len = 0 + next[prev_idx + 1];
            if (prev_idx == -1 || a[idx] > a[prev_idx])
            {
                len = max(len, 1 + next[idx + 1]);
            }

            curr[prev_idx + 1] = len;
        }
        next = curr;
    }

    return next[-1 + 1];
}