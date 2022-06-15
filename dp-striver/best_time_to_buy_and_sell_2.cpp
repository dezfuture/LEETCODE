#include <bits/stdc++.h>
using namespace std;

// ? memoization

long solve(int idx, int buy, long *values, int n, vector<vector<long>> &dp)
{
    if (idx == n)
    {
        return 0;
    }

    if (dp[idx][buy] != -1)
    {
        return dp[idx][buy];
    }

    long profit = 0;

    if (buy)
    {
        profit = max(-values[idx] + solve(idx + 1, 0, values, n, dp),
                     0 + solve(idx + 1, 1, values, n, dp));
    }
    else
    {
        profit = max(values[idx] + solve(idx + 1, 1, values, n, dp),
                     0 + solve(idx + 1, 0, values, n, dp));
    }

    return dp[idx][buy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return solve(0, 1, values, n, dp);
}


// ? tabulation

long solve(long *values, int n) {
    vector<vector<long>> dp(n+1, vector<long> (2, 0));
    dp[n][0] = dp[n][1] = 0;

    for (int i = n - 1; i >= 0;i --) {
        for (int buy = 0; buy <= 1; buy++) {
            long profit = 0;
            if(buy) {
                profit = max(-values[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
            }
            else {
                profit = max(values[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
            }

            dp[i][buy] = profit;
        }
    }

    return dp[0][1];
}