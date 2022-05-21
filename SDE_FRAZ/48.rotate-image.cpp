/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution
{
public:
    //     Algo:
    //     Take the transpose of the matrix
    //     Reverse every row

    void rotate(vector<vector<int>> &matrix)
    {
        int len = matrix.size();

        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < len; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
// @lc code=end
