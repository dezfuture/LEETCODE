/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int dist = 0, i = 0;
        while (i < n)
        {
            dist = max(dist, i + nums[i]);
            if (dist >= n - 1)
            {
                return true;
            }
            else if (dist <= i)
            {
                return false;
            }

            i++;
        }

        return false;
    }
    /*

    ! dp solution

    private:
        bool solve(vector<int> &v, int pos, vector<bool> &dp)
        {
            int n = v.size();
            if (pos >= n - 1)
            {
                return true;
            }

            // bool flag = false;

            for (int jump = 1; jump <= v[pos]; jump++)
            {

                if (pos + jump >= n)
                {
                    continue;
                }
                if (solve(v, pos + jump, dp))
                {
                    return true;
                }
            }

            dp[pos] = true;

            return false;
        }
    */
};
// @lc code=end
