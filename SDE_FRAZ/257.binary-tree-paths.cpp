/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    vector<vector<int>> temp;

    void solve(TreeNode *root, vector<int> &res)
    {
        if (!root)
        {
            return;
        }

        res.push_back(root->val);

        solve(root->left, res);
        solve(root->right, res);

        if (!root->left && !root->right)
        {
            temp.push_back(res);
        }

        res.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        vector<int> path;
        solve(root, path);

        for (int i = 0; i < temp.size(); i++)
        {
            string s = "";
            for (int j = 0; j < temp[i].size() - 1; j++)
            {
                s += to_string(temp[i][j]);
                s += "->";
            }

            s += to_string(temp[i][temp[i].size() - 1]);

            res.push_back(s);
        }

        return res;
    }
};
// @lc code=end
