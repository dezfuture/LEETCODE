class Solution
{
public:
    vector<int> printPath(TreeNode *root, int k)
    {
        vector<int> res;
        if (root == NULL)
        {
            return res;
        }

        solve(root, res, k);

        return res;
    }

private:
    void solve(TreeNode *root, vector<int> &res, int k)
    {
        if (!root)
        {
            return false;
        }

        res.push_back(root->val);

        if (root->val == k)
        {
            return true;
        }

        if (solve(root->left, res, k) || solve(root->right, res, k))
        {
            return true;
        }

        res.pop_back();

        return false;
    }
};