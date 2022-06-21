/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        TreeNode *temp = root;

        vector<int> res;
        stack<TreeNode *> s;

        while (1)
        {
            if (temp)
            {
                s.push(temp);
                temp = temp->left;
            }
            else
            {
                if (s.empty())
                {
                    break;
                }

                temp = s.top();
                s.pop();
                res.push_back(temp->val);
                temp = temp->right;
            }
        }

        return res;
    }
};
// @lc code=end
