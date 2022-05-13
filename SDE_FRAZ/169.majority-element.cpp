/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution
{
public:
    // Bitmasking method

    int majorityElement(vector<int> &nums)
    {
        int majority = 0;

        int len = nums.size();

        for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1)
        {
            int bits = 0;

            for (auto x : nums)
            {
                if (x & mask)
                {
                    bits++;
                }
            }

            if (bits > len / 2)
            {
                majority |= mask;
            }
        }

        return majority;
    }

    // method -> 2

    // int majorityElement(vector<int> &nums)
    // {
    //     int count = 0, element = 0;
    //     for (auto x : nums)
    //     {
    //         if (count == 0)
    //         {
    //             element = x;
    //         }

    //         if (element == x)
    //         {
    //             count++;
    //         }
    //         else
    //         {
    //             count--;
    //         }
    //     }

    //     return element;
    // }

    // simple approach

    // int majorityElement(vector<int> &nums)
    // {
    //     unordered_map<int, int> m;
    //     int n = nums.size();
    //     for (int i = 0; i < n; i++)
    //     {
    //         m[nums[i]]++;
    //     }

    //     int res = 0;
    //     int res1 = n / 2;

    //     for (auto it : m)
    //     {
    //         if (it.second > res1)
    //         {
    //             res = it.first;
    //             break;
    //         }
    //     }

    //     return res;
    // }
};
// @lc code=end
