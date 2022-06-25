/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    // ! we opt a recursive approach as in worst case the space complexity would only be the auxillary stack space

    // ! reverse preorder traversal

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        solve(root, 0, res);
        return res;
    }

private:
    void solve(TreeNode *root, int level, vector<int> &res)
    {
        if (root == NULL)
        {
            return;
        }

        // ? due to this technique the first element we encounter on the right we store it and move to the next level

        if (res.size() == level)
        {
            res.push_back(root->val);
        }

        solve(root->right, level + 1, res);
        solve(root->left, level + 1, res);
    }
};
// @lc code=end
