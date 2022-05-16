// * memoization

#include <bits/stdc++.h>

using namespace std;

int solveUtil(int ind, vector<int> &arr, vector<int> &dp)
{

    if (dp[ind] != -1)
        return dp[ind];

    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;

    int pick = arr[ind] + solveUtil(ind - 2, arr, dp);
    int nonPick = 0 + solveUtil(ind - 1, arr, dp);

    return dp[ind] = max(pick, nonPick);
}

int solve(int n, vector<int> &arr)
{
    vector<int> dp(n, -1);
    return solveUtil(n - 1, arr, dp);
}

int main()
{

    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    cout << solve(n, arr);
}

// * tabulation

int solve(int n, vector<int> &nums, vector<int> &dp)
{
    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }

        int notPick = dp[i - 1];

        dp[i] = max(pick, notPick);
    }

    return dp[n - 1];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(n, nums, dp);
}