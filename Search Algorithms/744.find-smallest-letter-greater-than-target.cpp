/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 *
 * https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
 *
 * algorithms
 * Easy (45.83%)
 * Likes:    1193
 * Dislikes: 1138
 * Total Accepted:    150.7K
 * Total Submissions: 329.4K
 * Testcase Example:  '["c","f","j"]\n"a"'
 *
 * Given a characters array letters that is sorted in non-decreasing order and
 * a character target, return the smallest character in the array that is
 * larger than target.
 *
 * Note that the letters wrap around.
 *
 *
 * For example, if target == 'z' and letters == ['a', 'b'], the answer is
 * 'a'.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: letters = ["c","f","j"], target = "a"
 * Output: "c"
 *
 *
 * Example 2:
 *
 *
 * Input: letters = ["c","f","j"], target = "c"
 * Output: "f"
 *
 *
 * Example 3:
 *
 *
 * Input: letters = ["c","f","j"], target = "d"
 * Output: "f"
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= letters.length <= 10^4
 * letters[i] is a lowercase English letter.
 * letters is sorted in non-decreasing order.
 * letters contains at least two different characters.
 * target is a lowercase English letter.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int low = 0, high = letters.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (target < letters[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return letters[low % letters.size()];
    }
};
// @lc code=end
