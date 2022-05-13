/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();

        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == num1)
            {
                count1++;
            }
            else if (nums[i] == num2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                num1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        vector<int> v;
        count1 = count2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == num1)
            {
                count1++;
            }
            if (nums[i] == num2)
            {
                count2++;
            }
        }

        int res = n / 3;

        if (num1 == num2)
        {
            if (count1 > res)
            {
                v.push_back(num1);
            }
            return v;
        }

        if (count1 > res)
        {
            v.push_back(num1);
        }
        if (count2 > res)
        {
            v.push_back(num2);
        }

        return v;
    }

    //* EASY HASHING SOLUTION

    // vector<int> majorityElement(vector<int> &nums)
    // {
    //     unordered_map<int, int> m;

    //     int len = nums.size();

    //     for (int i = 0; i < len; i++)
    //     {
    //         m[nums[i]]++;
    //     }

    //     int res = len / 3;
    //     vector<int> v;

    //     for (auto it : m)
    //     {
    //         if (it.second > res)
    //         {
    //             v.push_back(it.first);
    //         }
    //     }

    //     return v;
    // }
};
// @lc code=end
