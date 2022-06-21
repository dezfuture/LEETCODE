/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == NULL)
        {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++)
            {
                TreeNode *hell = q.front();
                q.pop();
                if (hell->left)
                {
                    q.push(hell->left);
                }
                if (hell->right)
                {
                    q.push(hell->right);
                }
                temp.push_back(hell->val);
            }
            res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end
