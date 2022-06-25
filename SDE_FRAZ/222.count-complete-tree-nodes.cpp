/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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

    // ? TC -> O((log(n))^2)

public:
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int l = left(root);
        int r = right(root);

        if (l == r)
        {
            return (1 << r) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int left(TreeNode *root)
    {
        int res = 0;

        while (root)
        {
            res++;
            root = root->left;
        }

        return res;
    }

    int right(TreeNode *root)
    {
        int res = 0;

        while (root)
        {
            res++;
            root = root->right;
        }

        return res;
    }
};
// @lc code=end
