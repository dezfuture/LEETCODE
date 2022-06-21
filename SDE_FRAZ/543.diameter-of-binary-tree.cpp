/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int diameter = 0;

    int solve(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int l = solve(root->left);
        int r = solve(root->right);

        diameter = max(diameter, l + r);

        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        solve(root);
        return diameter;
    }
};
// @lc code=end
