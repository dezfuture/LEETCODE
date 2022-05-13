// print all sub sequences with sum = k

void solve(int idx, vector<int> &ds, int s, int sum, int a[], int n)
{
    if (idx == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    ds.push_back(a[idx]);
    s += a[idx];

    solve(idx + 1, ds, s, sum, a, n);

    s -= a[idx];
    ds.pop_back();

    solve(idx + 1, ds, s, sum, a, n);
}

// print only one sub sequence

bool solve(int idx, vector<int> &ds, int s, int sum, int a[], int n)
{
    if (idx == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;

            return true;
        }
        else
            return false;
    }

    ds.push_back(a[idx]);
    s += a[idx];

    if (solve(idx + 1, ds, s, sum, a, n))
    {
        return true;
    }

    s -= a[idx];
    ds.pop_back();

    if (solve(idx + 1, ds, s, sum, a, n))
    {
        return true;
    }

    return false;
}

// for finding the number of subsequences do l and r and then return l+r

// * combination sum

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, candidates, ans, ds);
        return ans;
    }

private:
    void solve(int idx, int target, vector<int> &arr, vector<int> &ans, vector<int> &ds)
    {
        if (idx == arr.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }

            return;
        }

        // pickup the element

        if (arr[idx] <= target)
        {
            ds.pb(arr[idx]);
            solve(idx, target - arr[idx], arr, ans, ds);
            ds.pop_back();
        }

        solve(idx + 1, target, arr, ans, ds);
    }
};

//  ? Combination Sum - 2

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, candidates, ds, ans);
        return ans;
    }

private:
    void solve(int idx, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < arr.size(); i++)
        {
            if (i > idx && arr[i] == arr[i - 1])
            {
                continue;
            }

            if (arr[i] > target)
            {
                break;
            }

            ds.push_back(arr[i]);
            solve(i + 1, target - arr[i], arr, ds, ans);
            ds.pop_back();
        }
    }
};