/*
 * @lc app=leetcode id=1041 lang=cpp
 *
 * [1041] Robot Bounded In Circle
 *
 * https://leetcode.com/problems/robot-bounded-in-circle/description/
 *
 * algorithms
 * Medium (54.44%)
 * Likes:    2346
 * Dislikes: 548
 * Total Accepted:    154.2K
 * Total Submissions: 280.8K
 * Testcase Example:  '"GGLLGG"'
 *
 * On an infinite plane, a robot initially stands at (0, 0) and faces north.
 * The robot can receive one of three instructions:
 *
 *
 * "G": go straight 1 unit;
 * "L": turn 90 degrees to the left;
 * "R": turn 90 degrees to the right.
 *
 *
 * The robot performs the instructions given in order, and repeats them
 * forever.
 *
 * Return true if and only if there exists a circle in the plane such that the
 * robot never leaves the circle.
 *
 *
 * Example 1:
 *
 *
 * Input: instructions = "GGLLGG"
 * Output: true
 * Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and
 * then returns to (0,0).
 * When repeating these instructions, the robot remains in the circle of radius
 * 2 centered at the origin.
 *
 * Example 2:
 *
 *
 * Input: instructions = "GG"
 * Output: false
 * Explanation: The robot moves north indefinitely.
 *
 * Example 3:
 *
 *
 * Input: instructions = "GL"
 * Output: true
 * Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) ->
 * (0, 0) -> ...
 *
 *
 * Constraints:
 *
 *
 * 1 <= instructions.length <= 100
 * instructions[i] is 'G', 'L' or, 'R'.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool originVerifier(int x, int y)
    {
        if (x == 0 && y == 0)
            return true;
        return false;
    }

    bool isRobotBounded(string instructions)
    {
        char curr = 'N';
        int x = 0, y = 0;

        for (int i = 0; i < instructions.length(); i++)
        {
            if (instructions[i] == 'G')
            {
                y += curr == 'N' ? 1 : 0;
                y += curr == 'S' ? -1 : 0;
                x += curr == 'E' ? 1 : 0;
                x += curr == 'W' ? -1 : 0;
            }
            else
            {
                char s = instructions[i];

                if (curr == 'N')
                {
                    curr = s == 'L' ? 'W' : 'E';
                }
                else if (curr == 'S')
                {
                    curr = s == 'L' ? 'E' : 'W';
                }
                else if (curr == 'E')
                {
                    curr = s == 'L' ? 'N' : 'S';
                }
                else
                {
                    curr = s == 'L' ? 'S' : 'N';
                }
            }
        }

        if (originVerifier(x, y) || curr != 'N')
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
