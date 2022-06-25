/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
    // ~ ques values are stored as node, vertical, level

    // ~ use of multiset to store similar values at diff or same level in sorted order

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode *, pair<int, int>>> q;

        q.push({root, {0, 0}});

        vector<vector<int>> res;

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            auto node = p.first;
            int x = p.second.first;
            int y = p.second.second;

            m[x][y].insert(node->val);

            if (node->left)
            {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right)
            {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        for (auto p : m)
        {
            vector<int> col;

            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }

            res.push_back(col);
        }

        return res;
    }
};
// @lc code=end
