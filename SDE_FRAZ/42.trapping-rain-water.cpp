/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution
{
public:
    // ? prefix suffix array method

    // int trap(vector<int> &height)
    // {

    //     int n = height.size();
    //     int l = 0, r = 0;
    //     int prefix[n], suffix[n];

    //     for (int i = 0; i < n; i++)
    //     {
    //         l = max(l, height[i]);
    //         prefix[i] = l;
    //     }

    //     for (int i = n - 1; i >= 0; i--)
    //     {
    //         r = max(r, height[i]);
    //         suffix[i] = r;
    //     }

    //     int res = 0;

    //     for (int i = 0; i < n; i++)
    //     {
    //         res += (min(prefix[i], suffix[i]) - height[i]);
    //     }

    //     return res;
    // }

    // ? 2 pointer approach

    int trap(vector<int> &height)
    {
        int n = height.size();
        int left = 0, right = n - 1;
        int res = 0;
        int leftMax = 0, rightMax = 0;

        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= leftMax)
                {
                    leftMax = height[left];
                }
                else
                {
                    res += leftMax - height[left];
                }

                left++;
            }
            else
            {
                if (height[right] >= rightMax)
                {
                    rightMax = height[right];
                }
                else
                {
                    res += rightMax - height[right];
                }

                right--;
            }
        }

        return res;
    }
};
// @lc code=end
