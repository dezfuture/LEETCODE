/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int merge(vector<int> &v, int low, int mid, int high)
    {
        int count = 0;
        int j = mid + 1;

        for (int i = low; i <= mid; i++)
        {
            while (j <= high && v[i] > 2ll * v[j])
            {
                j++;
            }

            count += j - (mid + 1);
        }

        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (v[left] <= v[right])
            {
                temp.push_back(v[left++]);
            }
            else
            {
                temp.push_back(v[right++]);
            }
        }

        while (left <= mid)
        {
            temp.push_back(v[left++]);
        }

        while (right <= high)
        {
            temp.push_back(v[right++]);
        }

        for (int i = low; i <= high; i++)
        {
            v[i] = temp[i - low];
        }

        return count;
    }

    int mergeSort(vector<int> &v, int low, int high)
    {
        if (low >= high)
        {
            return 0;
        }

        int mid = (low + high) >> 1;

        int inv = mergeSort(v, low, mid);
        inv += mergeSort(v, mid + 1, high);
        inv += merge(v, low, mid, high);

        return inv;
    }
};
// @lc code=end
