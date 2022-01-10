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
    bool binary_search(vector<int> &arr, int target, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] < target)
            {
                // the value to be searched is greater than mid value thus target lies somewhere between mid+1 and end; hence we should continue search there.
                start = mid + 1;
            }
            else if (arr[mid] > target)
            {
                // the value to be searched is smaller than mid value thus target lies somewhere between start and mid-1; hence we should continue search there.
                end = mid - 1;
            }
            else
            {
                // value searched is mid value return mid index
                return true;
            }
        }
        return false;
    }

    bool search(vector<int> &nums, int target)
    {

        // idea is to access the pivot value first.
        // Pivot value in rotated array is the peak value after which values start decreasing and the increase again . Ex. [4,5,6,7,0,1,2,3] -> Rotated sorted array -> here 7 is pivot value.
        // Once we have the pivot, then by comparing it with target { and ranges } we can decide which array range should be used to apply binary search and search the value in O(log N) time

        // Finding pviot achieved by pivot()
        int pivotIndex = pivotWithDuplicates(nums);
        // Now we have the pivot, we have to binary search based on ranges.
        if (pivotIndex == -1)
        {
            // Implies array is not rotated hence normal binary search applies
            return binary_search(nums, target, 0, nums.size() - 1);
        }

        if (nums[pivotIndex] == target)
        {
            return true;
        }

        if (nums[0] <= target)
        {
            // value to be searched is greater than the first value thus target lies between start and pivotIndex
            return binary_search(nums, target, 0, pivotIndex - 1);
        }
        else
        {
            // value to be searched is smaller than the first value thus target lies between pivotIndex and end
            return binary_search(nums, target, pivotIndex + 1, nums.size() - 1);
        }
    }

    int pivotWithDuplicates(vector<int> &nums)
    {
        // For finding pivot, general approach of binary search is used
        // We take a mid value and based on the values ahead, behind of mid value and start value make certain inferences
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mid < end && nums[mid] > nums[mid + 1])
            {
                // mid value > mid+1 value in an ascending sorted rotated array
                // then mid value is certainly the pivot value as in an ascending array mid value < (mid+1) value {distinct values} thus mid and mid+1 is where the break happened.
                // Ex. 5 6 1 -> mid value = 6 , mid+1 value = 1 => mid>mid+1 => mid is pivot
                // mid<end check for preventing accessing array index out of bound using short circuit &&
                return mid;
            }

            if (mid > start && nums[mid] < nums[mid - 1])
            {
                // mid value < mid-1 value in an ascending sorted rotated array
                // then mid-1 valie is certainly the pivot value as in an ascending array mid value > (mid-1) value thus mid-1 and mid is where the break happened
                // Ex. 5 7 1 2 4 -> mid value = 1 , mid-1 value = 7 => mid-1>mid => mid-1 is pivot
                // mid>start check for preventing accessing array index out of bound using short circuit &&
                return mid - 1;
            }

            if (nums[start] == nums[mid] && nums[mid] == nums[end])
            {
                // attempt to reduce duplicates from consideration

                if (start == mid && mid == end)
                {
                    // implies array not rotated thus normal binary search to be applied
                    return -1;
                }

                if (nums[start] > nums[start + 1])
                {
                    // from the similar logic used above we can be certain that start is the pivot.
                    return start;
                }
                // removing duplicate start value if it is not pivot
                start++;

                if (nums[end - 1] > nums[end])
                {
                    // from the similar logic used above we can be certain that end is the pivot.
                    return end - 1;
                }
                // removing duplicate end value if it is not pivot
                end--;
            }
            else if (nums[start] < nums[mid] || (nums[start] == nums[mid] && nums[mid] > nums[end]))
            {
                // Implying left sub array is sorted correctly and we should search for the pivot in the right sub array
                start = mid + 1;
            }
            else
            {
                // Implying right sub array is sorted correctly and we should search for the pivot in the left sub array
                end = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end
