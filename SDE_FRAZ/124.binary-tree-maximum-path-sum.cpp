/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int res = -1e8;
        solve(root, res);
        return res;
    }

private:
    int solve(TreeNode *root, int &res)
    {
        if (!root)
        {
            return 0;
        }

        int left = max(0, solve(root->left, res));
        int right = max(0, solve(root->right, res));
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }
};
// @lc code=end
