long long int solve(vector<int> &res)
{
    int n = res.size();

    long long int prev = res[0];
    long long int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        long long int pick = res[i];

        if (i > 1)
        {
            pick += prev2;
        }

        long long int notPick = prev;

        long long int curr = max(pick, notPick);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}

long long int houseRobber(vector<int> &a)
{
    vector<int> res1;
    vector<int> res2;

    int n = a.size();

    if (n == 1)
    {
        return a[0];
    }

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            res1.push_back(a[i]);
        }

        if (i != 1)
        {
            res2.push_back(a[i]);
        }
    }

    long long int temp1 = solve(res1);
    long long int temp2 = solve(res2);

    return max(temp1, temp2);
}