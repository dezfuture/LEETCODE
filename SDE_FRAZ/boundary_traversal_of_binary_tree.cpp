/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

// ? Logic

// ~ left boundary excluding leaf nodes
// ~ leaf nodes
// ~ right boundary in reverse direction

bool isLeaf(TreeNode<int> *root)
{
    return !root->left && !root->right;
}

void addLeftBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *curr = root->left;

    while (curr)
    {
        if (!isLeaf(curr))
        {
            res.push_back(curr->val);
        }

        if (curr->left)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

void addRightBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *curr = root->right;
    vector<int> hell;

    while (curr)
    {
        if (!isLeaf(curr))
        {
            hell.push_back(curr->data);
        }

        if (curr->right)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }

    for (int i = hell.size() - 1; i >= 0; i--)
    {
        res.push_back(hell[i]);
    }
}

void addLeaves(TreeNode<int> *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
    {
        addLeaves(root->left, res);
    }
    if (root->right)
    {
        addLeaves(root->right, res);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> res;
    if (!root)
    {
        return res;
    }

    if (!isLeaf(root))
    {
        res.push_back(root->data);
    }

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}