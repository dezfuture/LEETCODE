/*************************************************************

    Following is the Binary Tree node structure.

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> *root)
{
    vector<int> res;
    map<int, int> m;

    queue<pair<BinaryTreeNode<int> *, int>> q;

    if (root == NULL)
    {
        return res;
    }

    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        BinaryTreeNode<int> *temp = it.first;
        int line = it.second;

        m[line] = temp->data;

        if (temp->left)
        {
            q.push({temp->left, line - 1});
        }
        if (temp->right)
        {
            q.push({temp->right, line + 1});
        }
    }

    for (auto it : m)
    {
        res.push_back(it.second);
    }
    return res;
}
