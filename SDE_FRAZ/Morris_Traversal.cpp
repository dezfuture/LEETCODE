#include <bits/stdc++.h>
using namespace std;

// ? threaded binary tree to reduce the space complexity of the inoreder traversal to O(1)

vector<int> getInorder(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            inorder.push(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;

            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
}