/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution
{
public:
    // ? 2 pointer

    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, sum = 0;
        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            while (sum >= target)
            {
                ans = min(ans, i - left + 1);
                sum -= nums[left++];
            }
        }

        return (ans != INT_MAX) ? ans : 0;
    }

    // ? BINARY SEARCH

    // int minSubArrayLen(int target, vector<int> &v)
    // {
    //     int n = v.size();
    //     vector<int> hell(n + 1, 0);
    //     int ans = INT_MAX;

    //     for (int i = 1; i <= n; i++)
    //     {
    //         hell[i] = hell[i - 1] + v[i - 1];
    //     }

    //     for (int i = 1; i <= n; i++)
    //     {
    //         int temp = target + hell[i - 1];

    //         auto bound = lower_bound(hell.begin(), hell.end(), temp);

    //         if (bound != hell.end())
    //         {
    //             ans = min(ans, static_cast<int>(bound - (hell.begin() + i - 1)));
    //         }
    //     }

    //     return (ans != INT_MAX) ? ans : 0;
    // }

    // ? BRUTE FORCE APPROACH

    // int minSubArrayLen(int target, vector<int> &nums)
    // {
    //     int n = nums.size();

    //     if (n == 0)
    //     {
    //         return 0;
    //     }
    //     vector<int> prefix(n);
    //     prefix[0] = nums[0];
    //     for (int i = 1; i < n; i++)
    //     {
    //         prefix[i] = prefix[i - 1] + nums[i];
    //     }

    //     int res = INT_MAX;

    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = i; j < n; j++)
    //         {
    //             int sum = prefix[j] - prefix[i] + nums[i];

    //             if (sum >= target)
    //             {
    //                 res = min(res, j - i + 1);
    //                 break;
    //             }
    //         }
    //     }

    //     return (res != INT_MAX) ? res : 0;
    // }
};
// @lc code=end
