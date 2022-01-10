/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 *
 * https://leetcode.com/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (48.95%)
 * Likes:    4031
 * Dislikes: 123
 * Total Accepted:    160K
 * Total Submissions: 324.8K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * Given an array nums which consists of non-negative integers and an integer
 * m, you can split the array into m non-empty continuous subarrays.
 *
 * Write an algorithm to minimize the largest sum among these m subarrays.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [7,2,5,10,8], m = 2
 * Output: 18
 * Explanation:
 * There are four ways to split nums into two subarrays.
 * The best way is to split it into [7,2,5] and [10,8],
 * where the largest sum among the two subarrays is only 18.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4,5], m = 2
 * Output: 9
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,4,4], m = 3
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 10^6
 * 1 <= m <= min(50, nums.length)
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int start = 0, end = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            start = max(start, nums[i]);
            end += nums[i];
        }

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            int sum = 0, peices = 1;

            for (auto x : nums)
            {
                if (sum + x > mid)
                {
                    peices++;
                    sum = x;
                }
                else
                {
                    sum += x;
                }
            }

            if (peices > m)
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }

        return start;
    }
};
// @lc code=end

/*
// BOTTOM UP
class Solution
{
public:
    // Defined it as per the maximum size of array and split count
    // But can be defined with the input size as well
    int memo[1001][51];

    int splitArray(vector<int> &nums, int m)
    {
        int n = nums.size();

        // Store the prefix sum of nums array
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        for (int subarrayCount = 1; subarrayCount <= m; subarrayCount++)
        {
            for (int currIndex = 0; currIndex < n; currIndex++)
            {
                // Base Case: If there is only one subarray left, then all of the remaining numbers
                // must go in the current subarray. So return the sum of the remaining numbers.
                if (subarrayCount == 1)
                {
                    memo[currIndex][subarrayCount] = prefixSum[n] - prefixSum[currIndex];
                    continue;
                }

                // Otherwise, use the recurrence relation to determine the minimum largest subarray
                // sum between currIndex and the end of the array with subarrayCount subarray remaining.
                int minimumLargestSplitSum = INT_MAX;
                for (int i = currIndex; i <= n - subarrayCount; i++)
                {
                    // Store the sum of the first subarray.
                    int firstSplitSum = prefixSum[i + 1] - prefixSum[currIndex];

                    // Find the maximum subarray sum for the current first split.
                    int largestSplitSum = max(firstSplitSum, memo[i + 1][subarrayCount - 1]);

                    // Find the minimum among all possible combinations.
                    minimumLargestSplitSum = min(minimumLargestSplitSum, largestSplitSum);

                    if (firstSplitSum >= minimumLargestSplitSum)
                    {
                        break;
                    }
                }

                memo[currIndex][subarrayCount] = minimumLargestSplitSum;
            }
        }

        return memo[0][m];
    }
};

*/

// TOP DOWN

/*
class Solution {
public:
    // Defined it as per the maximum size of array and split count
    // But can be defined with the input size as well
    int memo[1001][51];

    int getMinimumLargestSplitSum(vector<int>& prefixSum, int currIndex, int subarrayCount) {
        int n = prefixSum.size() - 1;

        // We have already calculated the answer so no need to go into recursion
        if (memo[currIndex][subarrayCount] != -1) {
            return memo[currIndex][subarrayCount];
        }

        // Base Case: If there is only one subarray left, then all of the remaining numbers
        // must go in the current subarray. So return the sum of the remaining numbers.
        if (subarrayCount == 1) {
            return memo[currIndex][subarrayCount] = prefixSum[n] - prefixSum[currIndex];
        }

        // Otherwise, use the recurrence relation to determine the minimum largest subarray
        // sum between currIndex and the end of the array with subarrayCount subarrays remaining.
        int minimumLargestSplitSum = INT_MAX;
        for (int i = currIndex; i <= n - subarrayCount; i++) {
            // Store the sum of the first subarray.
            int firstSplitSum = prefixSum[i + 1] - prefixSum[currIndex];

            // Find the maximum subarray sum for the current first split.
            int largestSplitSum = max(firstSplitSum,
                                      getMinimumLargestSplitSum(prefixSum, i + 1, subarrayCount - 1));

            // Find the minimum among all possible combinations.
            minimumLargestSplitSum = min(minimumLargestSplitSum, largestSplitSum);

            if (firstSplitSum >= minimumLargestSplitSum) {
                break;
            }
        }

        return memo[currIndex][subarrayCount] = minimumLargestSplitSum;
    }

    int splitArray(vector<int>& nums, int m) {
        // Marking all values to -1 so that we can differentiate
        // If we have already calculated the answer or not
        memset(memo, -1, sizeof(memo));

        // Store the prefix sum of nums array.
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        return getMinimumLargestSplitSum(prefixSum, 0, m);
    }
};

*/