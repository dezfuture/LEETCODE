/*
 * @lc app=leetcode id=1041 lang=cpp
 *
 * [1041] Robot Bounded In Circle
 */

// @lc code=start
class Solution
{
public:
    bool isRobotBounded(string hell)
    {
        pair<int, int> pos = {0, 0}, dir = {0, 1};

        for (auto x : hell)
        {
            if (x == 'L')
            {
                dir = {-dir.second, dir.first};
            }
            else if (x == 'R')
            {
                dir = {dir.second, -dir.first};
            }
            else
            {
                pos = {pos.first + dir.first, pos.second + dir.second};
            }
        }

        return ((pos.first == 0 && pos.second == 0) || (dir.first != 0 || dir.second != 1));
    }
};
// @lc code=end
