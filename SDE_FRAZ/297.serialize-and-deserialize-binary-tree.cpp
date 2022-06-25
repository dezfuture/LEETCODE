/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
        {
            return "";
        }

        string s = "";
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *res = q.front();
            q.pop();

            if (res == NULL)
            {
                s.append("#,");
            }
            else
            {
                s.append(to_string(res->val) + ',');
            }

            if (res != NULL)
            {
                q.push(res->left);
                q.push(res->right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
        {
            return NULL;
        }
        // ? converting it into stringstream so that we can now use the getline seperator operation
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *res = q.front();
            q.pop();

            getline(s, str, ',');
            if (str == "#")
            {
                res->left = NULL;
            }
            else
            {
                TreeNode *hell = new TreeNode(stoi(str));
                res->left = hell;
                q.push(hell);
            }

            getline(s, str, ',');
            if (str == "#")
            {
                res->right = NULL;
            }
            else
            {
                TreeNode *hell = new TreeNode(stoi(str));
                res->right = hell;
                q.push(hell);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
