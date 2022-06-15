// ! same question just change the capacity from 2 to k

#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int tran, vector<int> &v, int n, int k, vector<vector<int>> &dp)
{
    if (idx == n || tran == 2 * k)
    {
        return 0;
    }

    if (dp[idx][tran] != -1)
    {
        return dp[idx][tran];
    }

    if (tran % 2)
    {
        return dp[idx][tran] = max(v[idx] + solve(idx + 1, tran + 1, v, n, k, dp), solve(idx + 1, tran, v, n, k, dp));
    }
    else
    {
        return dp[idx][tran] = max(-v[idx] + solve(idx + 1, tran + 1, v, n, k, dp), solve(idx + 1, tran, v, n, k, dp));
    }
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    vector<vector<int>> dp(n, vector<int>(2 * k, -1));

    return solve(0, 0, prices, n, k, dp);
}
