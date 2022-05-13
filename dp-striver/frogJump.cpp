// * memoization

int solve(int idx, vector<int> &heights, vector<int> &dp)
{
    if (idx == 0)
    {
        return 0;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int jumpTwo = INT_MAX;

    int jumpOne = solve(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);

    if (idx >= 1)
    {
        jumpTwo = solve(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);
    }

    return dp[idx] = min(jumpOne, jumpTwo);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    int res = solve(n - 1, heights, dp);
    return res;
}

//  * tabulation

#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int ind = 1; ind < n; ind++)
    {
        int jumpTwo = INT_MAX;
        int jumpOne = dp[ind - 1] + abs(height[ind] - height[ind - 1]);
        if (ind > 1)
            jumpTwo = dp[ind - 2] + abs(height[ind] - height[ind - 2]);

        dp[ind] = min(jumpOne, jumpTwo);
    }
    cout << dp[n - 1];
}

// * space optimized

#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {

        int jumpTwo = INT_MAX;
        int jumpOne = prev + abs(height[i] - height[i - 1]);
        if (i > 1)
            jumpTwo = prev2 + abs(height[i] - height[i - 2]);

        int cur_i = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = cur_i;
    }
    cout << prev;
}