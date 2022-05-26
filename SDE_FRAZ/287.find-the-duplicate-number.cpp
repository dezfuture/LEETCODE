/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution
{
public:
    // ? Floyd Warshall

    int findDuplicate(vector<int> &v)
    {
        int slow = 0, fast = 0;

        while (1)
        {
            slow = v[slow];
            fast = v[v[fast]];

            if (fast == slow)
            {
                break;
            }
        }

        int res = 0;

        while (1)
        {
            slow = v[slow];
            res = v[res];

            if (slow == res)
            {
                return res;
            }
        }

        return -1;
    }

    // ? cyclic sort technique

    // int findDuplicate(vector<int> &nums)
    // {
    //     int i = 0;
    //     int n = nums.size();

    //     while (i < n)
    //     {
    //         int temp = nums[i] - 1;
    //         if (nums[i] != nums[temp])
    //         {
    //             swap(nums[i], nums[temp]);
    //         }
    //         else
    //         {
    //             i++;
    //         }
    //     }

    //     for (int i = 0; i < n; i++)
    //     {
    //         if (nums[i] != i + 1)
    //         {
    //             return nums[i];
    //         }
    //     }

    //     return -1;
    // }
};
// @lc code=end
