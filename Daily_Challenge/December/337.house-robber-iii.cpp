/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (53.08%)
 * Likes:    5525
 * Dislikes: 87
 * Total Accepted:    260.5K
 * Total Submissions: 490.8K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * The thief has found himself a new place for his thievery again. There is
 * only one entrance to this area, called root.
 *
 * Besides the root, each house has one and only one parent house. After a
 * tour, the smart thief realized that all houses in this place form a binary
 * tree. It will automatically contact the police if two directly-linked houses
 * were broken into on the same night.
 *
 * Given the root of the binary tree, return the maximum amount of money the
 * thief can rob without alerting the police.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,2,3,null,3,null,1]
 * Output: 7
 * Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,4,5,1,3,null,1]
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * 0 <= Node.val <= 10^4
 *
 *
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
// class Solution
// {
// public:
//     int rob(TreeNode *root)
//     {
//         int left_max = 0, right_max = 0;
//         if (root == NULL)
//         {
//             return 0;
//         }
//         unordered_map<TreeNode *, int> m;
//         if (m[root])
//         {
//             return m[root];
//         }

//         if (root->left)
//         {
//             left_max = rob(root->left->right) + rob(root->left->left);
//         }

//         if (root->right)
//         {
//             right_max = rob(root->right->left) + rob(root->right->right);
//         }

//         return m[root] = max(root->val + right_max + left_max, rob(root->left) + rob(root->right));
//     }
// };

class Solution
{
    int max_num = INT_MIN;

public:
    unordered_map<TreeNode *, int> umap;
    int helper(TreeNode *root)
    {

        if (root == NULL)
            return 0;
        if (umap[root])
            return umap[root];
        int left_max = 0;
        int right_max = 0;
        if (root->left)
        {
            left_max = helper(root->left->left) + helper(root->left->right);
        }
        if (root->right)
        {
            right_max = helper(root->right->left) + helper(root->right->right);
        }

        return umap[root] = max(root->val + left_max + right_max, helper(root->left) + helper(root->right));
    }

    int rob(TreeNode *root)
    {
        return helper(root);
    }
};
// @lc code=end
