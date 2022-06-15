int stockProfit(vector<int> &v)
{
    int n = v.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][1] = max(-v[i] + dp[i + 1][0], dp[i + 1][1]);

        dp[i][0] = max(v[i] + dp[i + 2][1], dp[i + 1][0]);
    }

    return dp[0][1];
}

// ! here we don't need the buy for loop as both the conditions of buy are already stated