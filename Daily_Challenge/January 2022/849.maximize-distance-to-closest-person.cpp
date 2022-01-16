/*
 * @lc app=leetcode id=849 lang=cpp
 *
 * [849] Maximize Distance to Closest Person
 *
 * https://leetcode.com/problems/maximize-distance-to-closest-person/description/
 *
 * algorithms
 * Medium (44.90%)
 * Likes:    2310
 * Dislikes: 154
 * Total Accepted:    155K
 * Total Submissions: 329.2K
 * Testcase Example:  '[1,0,0,0,1,0,1]'
 *
 * You are given an array representing a row of seats where seats[i] = 1
 * represents a person sitting in the i^th seat, and seats[i] = 0 represents
 * that the i^th seat is empty (0-indexed).
 *
 * There is at least one empty seat, and at least one person sitting.
 *
 * Alex wants to sit in the seat such that the distance between him and the
 * closest person to him is maximized. 
 *
 * Return that maximum distance to the closest person.
 *
 *
 * Example 1:
 *
 *
 * Input: seats = [1,0,0,0,1,0,1]
 * Output: 2
 * Explanation:
 * If Alex sits in the second open seat (i.e. seats[2]), then the closest
 * person has distance 2.
 * If Alex sits in any other open seat, the closest person has distance 1.
 * Thus, the maximum distance to the closest person is 2.
 *
 *
 * Example 2:
 *
 *
 * Input: seats = [1,0,0,0]
 * Output: 3
 * Explanation:
 * If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats
 * away.
 * This is the maximum distance possible, so the answer is 3.
 *
 *
 * Example 3:
 *
 *
 * Input: seats = [0,1]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= seats.length <= 2 * 10^4
 * seats[i] is 0 or 1.
 * At least one seat is empty.
 * At least one seat is occupied.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int len = seats.size();

        int p = -1, res = INT_MIN;

        for (int i = 0; i < len; i++)
        {
            if (seats[i] == 1)
            {
                if (p == -1)
                {
                    res = i;
                }
                else
                {
                    res = max(res, (i - p) / 2);
                }

                p = i;
            }
        }

        res = max(res, len - 1 - p);
        return res;
    }
};
// @lc code=end
