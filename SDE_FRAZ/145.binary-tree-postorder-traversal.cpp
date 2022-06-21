/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode *root)
    {

        // ? using single stack

        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *curr = root;

        while (curr != NULL || !s.empty())
        {
            if (curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            else
            {
                TreeNode *temp = s.top()->right;
                if (temp == NULL)
                {
                    temp = s.top();
                    s.pop();
                    res.push_back(temp->val);
                    while (!s.empty() && temp == s.top()->right)
                    {
                        temp = s.top();
                        s.pop();
                        res.push_back(temp->val);
                    }
                }
                else
                {
                    curr = temp;
                }
            }
        }
        return res;

        //  ? using 2 stacks

        /*
                stack<TreeNode *> s1, s2;
                vector<int> res;

                if (root == NULL)
                {
                    return res;
                }

                s1.push(root);

                while (!s1.empty())
                {
                    root = s1.top();
                    s1.pop();
                    s2.push(root);

                    if (root->left)
                    {
                        s1.push(root->left);
                    }

                    if (root->right)
                    {
                        s1.push(root->right);
                    }
                }

                while (!s2.empty())
                {
                    res.push_back(s2.top()->val);
                    s2.pop();
                }

                return res;
                */
    }
};
// @lc code=end
