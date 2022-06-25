
#include <bits/stdc++.h>

vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> res;
    if (root == NULL)
    {
        return res;
    }

    map<int, int> m;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode<int> *temp = it.first;
        int line = it.second;

        if (m.find(line) == m.end())
        {
            m[line] = temp->val;
        }

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