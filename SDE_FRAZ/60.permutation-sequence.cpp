/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> v;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            v.push_back(i);
        }

        // ? because we need (n-1)!
        v.push_back(n);
        k -= 1;

        string ans = "";

        while (1)
        {
            ans += to_string(v[k / fact]);
            v.erase(v.begin() + k / fact);
            if (v.size() == 0)
            {
                break;
            }

            k = k % fact;
            fact = fact / v.size();
        }

        return ans;
    }
};
// @lc code=end
