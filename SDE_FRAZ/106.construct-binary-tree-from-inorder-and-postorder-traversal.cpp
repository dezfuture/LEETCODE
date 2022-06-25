/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        map<int, int> m;

        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }

        TreeNode *hell = solve(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, m);

        return hell;
    }

private:
    TreeNode *solve(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int posStart, int posEnd, map<int, int> &m)
    {
        if (inStart > inEnd || posStart > posEnd)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(postorder[posEnd]);

        int inRoot = m[root->val];
        int freq = inRoot - inStart;

        root->left = solve(inorder, inStart, inRoot - 1, postorder, posStart, posStart + freq - 1, m);
        root->right = solve(inorder, inRoot + 1, inEnd, postorder, posStart + freq, posEnd - 1, m);

        return root;
    }
};
// @lc code=end
