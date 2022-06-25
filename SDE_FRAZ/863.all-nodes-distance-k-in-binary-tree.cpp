/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        // ? for storing the parents as we cannot traverse in the upward direction
        unordered_map<TreeNode *, TreeNode *> m;
        solve(root, target, m);

        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;

        q.push(target);
        visited[target] = true;

        int level = 0;

        while (!q.empty())
        {
            int len = q.size();
            if (level++ == k)
            {
                break;
            }

            for (int i = 0; i < len; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                if (curr->right && !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }

                // ? for traversing radially outwards

                if (m[curr] && !visited[m[curr]])
                {
                    q.push(m[curr]);
                    visited[m[curr]] = true;
                }
            }
        }

        vector<int> res;

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            res.push_back(temp->val);
        }

        return res;
    }

private:
    void solve(TreeNode *root, TreeNode *target, unordered_map<TreeNode *, TreeNode *> &m)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left)
            {
                q.push(curr->left);
                m[curr->left] = curr;
            }

            if (curr->right)
            {
                q.push(curr->right);
                m[curr->right] = curr;
            }
        }
    }
};
// @lc code=end
