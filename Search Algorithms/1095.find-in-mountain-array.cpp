/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 *
 * https://leetcode.com/problems/find-in-mountain-array/description/
 *
 * algorithms
 * Hard (35.85%)
 * Likes:    936
 * Dislikes: 52
 * Total Accepted:    36.8K
 * Total Submissions: 102.8K
 * Testcase Example:  '[1,2,3,4,5,3,1]\n3'
 *
 * (This problem is an interactive problem.)
 *
 * You may recall that an array arr is a mountain array if and only if:
 *
 *
 * arr.length >= 3
 * There exists some i with 0 < i < arr.length - 1 such that:
 *
 * arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 *
 *
 *
 *
 * Given a mountain array mountainArr, return the minimum index such that
 * mountainArr.get(index) == target. If such an index does not exist, return
 * -1.
 *
 * You cannot access the mountain array directly. You may only access the array
 * using a MountainArray interface:
 *
 *
 * MountainArray.get(k) returns the element of the array at index k
 * (0-indexed).
 * MountainArray.length() returns the length of the array.
 *
 *
 * Submissions making more than 100 calls to MountainArray.get will be judged
 * Wrong Answer. Also, any solutions that attempt to circumvent the judge will
 * result in disqualification.
 *
 *
 * Example 1:
 *
 *
 * Input: array = [1,2,3,4,5,3,1], target = 3
 * Output: 2
 * Explanation: 3 exists in the array, at index=2 and index=5. Return the
 * minimum index, which is 2.
 *
 * Example 2:
 *
 *
 * Input: array = [0,1,2,4,2,1], target = 3
 * Output: -1
 * Explanation: 3 does not exist in the array, so we return -1.
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= mountain_arr.length() <= 10^4
 * 0 <= target <= 10^9
 * 0 <= mountain_arr.get(index) <= 10^9
 *
 *
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &m)
    {
        int index = peakIndex(0, m.length() - 1, m);

        if (m.get(index) == target)
        {
            return index;
        }

        int Lres = binary1(0, index - 1, target, m);
        if (Lres != -1)
        {
            return Lres;
        }
        int Rres = binary2(index + 1, m.length() - 1, target, m);
        if (Rres != -1)
        {
            return Rres;
        }
        return -1;
    }

private:
    int peakIndex(int low, int high, MountainArray &mountainArr)
    {
        if (low > high)
        {
            return -1;
        }

        int mid = low + (high - low) / 2;

        int a = mountainArr.get(mid - 1);
        int b = mountainArr.get(mid);
        int c = mountainArr.get(mid + 1);

        if (a < b && b > c)
        {
            return mid;
        }

        if (b < c)
        {
            return peakIndex(mid, high, mountainArr);
        }

        return peakIndex(low, mid, mountainArr);
    }

    int binary1(int low, int high, int target, MountainArray &mountainArr)
    {
        if (low > high)
        {
            return -1;
        }

        int mid = low + (high - low) / 2;

        int b = mountainArr.get(mid);

        if (b == target)
        {
            return mid;
        }

        if (b < target)
            return binary1(mid + 1, high, target, mountainArr);

        else
            return binary1(low, mid - 1, target, mountainArr);
    }

    int binary2(int low, int high, int target, MountainArray &mountainArr)
    {
        if (low > high)
            return -1;

        int mid = (low + high) / 2;

        int b = mountainArr.get(mid);

        if (b == target)
            return mid;

        if (b > target)
            return binary2(mid + 1, high, target, mountainArr);

        else
            return binary2(low, mid - 1, target, mountainArr);
    }
};
// @lc code=end
