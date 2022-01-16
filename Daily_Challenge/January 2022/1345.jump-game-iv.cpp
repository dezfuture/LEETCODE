/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 *
 * https://leetcode.com/problems/jump-game-iv/description/
 *
 * algorithms
 * Hard (42.12%)
 * Likes:    1550
 * Dislikes: 65
 * Total Accepted:    61.3K
 * Total Submissions: 138.8K
 * Testcase Example:  '[100,-23,-23,404,100,23,23,23,3,404]'
 *
 * Given an array of integers arr, you are initially positioned at the first
 * index of the array.
 *
 * In one step you can jump from index i to index:
 *
 *
 * i + 1 where: i + 1 < arr.length.
 * i - 1 where: i - 1 >= 0.
 * j where: arr[i] == arr[j] and i != j.
 *
 *
 * Return the minimum number of steps to reach the last index of the array.
 *
 * Notice that you can not jump outside of the array at any time.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
 * Output: 3
 * Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that
 * index 9 is the last index of the array.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [7]
 * Output: 0
 * Explanation: Start index is the last index. You do not need to jump.
 *
 *
 * Example 3:
 *
 *
 * Input: arr = [7,6,9,6,9,6,9,7]
 * Output: 1
 * Explanation: You can jump directly from index 0 to index 7 which is last
 * index of the array.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 5 * 10^4
 * -10^8 <= arr[i] <= 10^8
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int len = arr.size();
        unordered_map<int, vector<int>> m;

        for (size_t i = 0; i < len; i++)
        {
            m[arr[i]].push_back(i);
        }

        vector<bool> v(len, false);
        v[0] = true;

        queue<int> q;
        q.push(0);
        int res = 0;

        while (!q.empty())
        {
            for (int size = q.size(); size > 0; size--)
            {
                int i = q.front();
                q.pop();

                if (i == len - 1)
                {
                    return res;
                }

                vector<int> &hell = m[arr[i]];

                hell.push_back(i - 1);
                hell.push_back(i + 1);

                for (auto j : hell)
                {
                    if (j > 0 && j < len && !v[j])
                    {
                        q.push(j);
                        v[j] = true;
                    }
                }

                hell.clear();
            }

            res++;
        }

        return res;
    }
};
// @lc code=end
