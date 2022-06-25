/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }

        return solve(root->left, root->right);
    }

private:
    bool solve(TreeNode *a, TreeNode *b)
    {
        if (!a && !b)
        {
            return true;
        }

        if (!a || !b)
        {
            return false;
        }

        return (a->val == b->val) && solve(a->left, b->right) && solve(a->right, b->left);
    }
};
// @lc code=end
