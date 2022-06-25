#include <bits/stdc++.h>
using namespace std;

int findMaxTime(map<TreeNode *, TreeNode *> &m, TreeNode *target)
{
    queue<TreeNode *> q;
    map<TreeNode *, bool> visited;
    q.push(target);
    visited[target] = true;
    int mxn = 0;

    while (!q.empty())
    {
        int len = q.size();
        bool flag = false;

        for (int i = 0; i < len; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left && !visited[curr->left])
            {
                flag = true;
                visited[curr->left] = true;
                q.push(curr->left);
            }

            if (curr->right && !visited[curr->right])
            {
                flag = true;
                visited[curr->right] = true;
                q.push(curr->right);
            }

            if (m[curr] && !visited[m[curr]])
            {
                flag = true;
                visited[m[curr] = true;
                q.push(m[curr]);
            }
        }

        if (flag)
        {
            mxn++;
        }
    }

    return mxn;
}

TreeNode *bfsToMapParents(TreeNode *root, map<TreeNode *, TreeNode *> &m, int start)
{
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *res;

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        if (curr->val == start)
        {
            res = curr;
        }
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

    return res;
}

int timeToBurn(TreeNode *root, itn start)
{
    map<TreeNode *, TreeNode *> m;
    TreeNode *target = bfsToMapParents(root, m, start);
    int time = findMaxTime(m, target);
    return time;
}
