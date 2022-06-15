#include <bits/stdc++.h>
using namespace std;

vector<int> divisibleSet(vector<int> &a)
{
    int n = a.size();

    vector<int> dp(n, 1), hash(n);

    sort(a.begin(), a.end());

    int maxi = 1, lastIdx = 0;

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (a[i] % a[prev] == 0 && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }

        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIdx = i;
        }
    }

    vector<int> temp;
    temp.push_back(a[lastIdx]);

    while (hash[lastIdx] != lastIdx)
    {
        lastIdx = hash[lastIdx];
        temp.push_back(a[lastIdx]);
    }

    reverse(temp.begin(), temp.end());

    return temp;
}
