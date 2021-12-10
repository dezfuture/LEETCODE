/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 *
 * https://leetcode.com/problems/last-stone-weight-ii/description/
 *
 * algorithms
 * Medium (49.70%)
 * Likes:    1811
 * Dislikes: 67
 * Total Accepted:    45.5K
 * Total Submissions: 91.6K
 * Testcase Example:  '[2,7,4,1,8,1]'
 *
 * You are given an array of integers stones where stones[i] is the weight of
 * the i^th stone.
 *
 * We are playing a game with the stones. On each turn, we choose any two
 * stones and smash them together. Suppose the stones have weights x and y with
 * x <= y. The result of this smash is:
 *
 *
 * If x == y, both stones are destroyed, and
 * If x != y, the stone of weight x is destroyed, and the stone of weight y has
 * new weight y - x.
 *
 *
 * At the end of the game, there is at most one stone left.
 *
 * Return the smallest possible weight of the left stone. If there are no
 * stones left, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: stones = [2,7,4,1,8,1]
 * Output: 1
 * Explanation:
 * We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
 * we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
 * we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
 * we can combine 1 and 1 to get 0, so the array converts to [1], then that's
 * the optimal value.
 *
 *
 * Example 2:
 *
 *
 * Input: stones = [31,26,33,21,40]
 * Output: 5
 *
 *
 * Example 3:
 *
 *
 * Input: stones = [1,2]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= stones.length <= 30
 * 1 <= stones[i] <= 100
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int range = 0;

        for (auto x : stones)
            range += x;

        vector<int> v = last_row_subset_sum(stones, range);

        int mn = INT_MAX;
        for (auto x : v)
            mn = min(mn, range - 2 * x);

        return mn;
    }

private:
    vector<int> last_row_subset_sum(vector<int> &stones, int range)
    {
        int n = stones.size();
        bool dp[n + 1][range + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= range; j++)
            {
                if (i == 0)
                    dp[i][j] = false;
                if (j == 0)
                    dp[i][j] = true;
            }
        }

        for (int i = 1; i <= n; i++)
        {

            for (int j = 1; j <= range; j++)
            {
                if (stones[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - stones[i - 1]];
                else if (stones[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
            }
        }

        vector<int> v;

        for (int i = 0; i <= range / 2; i++)
        {
            if (dp[n][i])
                v.push_back(i);
        }

        return v;
    }
};
// @lc code=end
