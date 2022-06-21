/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool flag = true;

    int solve(TreeNode *root)
    {
        int l = 0, r = 0;

        if (root->left)
        {
            l = solve(root->left);
        }

        if (root->right)
        {
            r = solve(root->right);
        }

        if (abs(l - r) > 1)
        {
            flag = false;
        }

        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        solve(root);

        return flag;
    }
};
// @lc code=end
