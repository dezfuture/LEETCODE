/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (34.25%)
 * Likes:    3101
 * Dislikes: 636
 * Total Accepted:    356.3K
 * Total Submissions: 1M
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * There is an integer array nums sorted in non-decreasing order (not
 * necessarily with distinct values).
 *
 * Before being passed to your function, nums is rotated at an unknown pivot
 * index k (0 <= k < nums.length) such that the resulting array is [nums[k],
 * nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 * For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and
 * become [4,5,6,6,7,0,1,2,4,4].
 *
 * Given the array nums after the rotation and an integer target, return true
 * if target is in nums, or false if it is not in nums.
 *
 * You must decrease the overall operation steps as much as possible.
 *
 *
 * Example 1:
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * Example 2:
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * nums is guaranteed to be rotated at some pivot.
 * -10^4 <= target <= 10^4
 *
 *
 *
 * Follow up: This problem is similar to Search in Rotated Sorted Array, but
 * nums may contain duplicates. Would this affect the runtime complexity? How
 * and why?
 *
 */

// @lc code=start
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int pivot = findPivotWithDuplicates(nums);

        if (pivot == -1)
        {
            return binarySearch(nums, target, 0, nums.size() - 1);
        }

        if (nums[pivot] == target)
        {

            return pivot;
        }

        if (target >= nums[0])
        {
            return binarySearch(nums, target, 0, pivot - 1);
        }

        return binarySearch(nums, target, pivot + 1, nums.size() - 1);
    }

private:
    int binarySearch(vector<int> &nums, int target, int low, int high)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (target < nums[mid])
            {
                high = mid - 1;
            }
            else if (target > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        return -1;
    }

    int findPivotWithDuplicates(vector<int> &nums)
    {
        int start = 0, end = nums.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (mid < end && nums[mid] > nums[mid + 1])
            {
                return mid;
            }

            if (mid > start && nums[mid] < nums[mid - 1])
            {
                return mid - 1;
            }

            // if elements at middle, start and end are equal
            if (nums[mid] == nums[start] && nums[end] == nums[mid])
            {
                if (start < end && nums[start] > nums[start + 1])
                {
                    return start;
                }

                start++;

                if (end > start && nums[end] < nums[end - 1])
                {
                    return end - 1;
                }
                end--;
            }
            else if (nums[start] < nums[mid] && (nums[start] == nums[mid] && nums[mid] > nums[end]))
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return -1;
    }
};
// @lc code=end
