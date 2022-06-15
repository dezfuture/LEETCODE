// ? memoization

int solve(int idx, int buy, int cap, vector<int> &v, vector<vector<vector<int>>> &dp, int n)
{
    if (cap == 0 || idx == n)
    {
        return 0;
    }

    if (dp[idx][buy][cap] != -1)
    {
        return dp[idx][buy][cap];
    }

    if (buy)
    {
        return dp[idx][buy][cap] = max(-v[idx] + solve(idx + 1, 0, cap, v, dp, n),
                                       solve(idx + 1, 1, cap, v, dp, n));
    }
    else
    {
        return dp[idx][buy][cap] = max(v[idx] + solve(idx + 1, 1, cap - 1, v, dp, n),
                                       solve(idx + 1, 0, cap, v, dp, n));
    }
}

int maxProfit(vector<int> &v, int n)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    return solve(0, 1, 2, v, dp, n);
}

// ? space optimization

int maxProfit(vector<int> &v, int n)
{
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy)
                {
                    curr[buy][cap] = max(-v[i] + after[0][cap], after[1][cap]);
                }
                else
                {
                    curr[buy][cap] = max(v[i], after[1][cap - 1], after[0][cap]);
                }
            }
        }

        after = curr;
    }

    return after[1][2];
}