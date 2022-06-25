/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
  // ? the logic is simple store the level order traversal and alternatively reverse the stored vector
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    vector<vector<int>> res;
    queue<TreeNode *> q;
    if (root == NULL)
    {
      return res;
    }

    q.push(root);

    while (!q.empty())
    {
      vector<int> temp;
      int size = q.size();

      for (int i = 0; i < size; i++)
      {
        TreeNode *hell = q.front();
        q.pop();

        if (hell->left)
        {
          q.push(hell->left);
        }
        if (hell->right)
        {
          q.push(hell->right);
        }

        temp.push_back(hell->val);
      }

      res.push_back(temp);
    }

    for (int i = 0; i < res.size(); i++)
    {
      if (i & 1)
      {
        reverse(res[i].begin(), res[i].end());
      }
    }

    return res;
  }

  // ? more general solution

  /*

#include<bits/stdc++.h>

using namespace std;

class Node {
  public:
    int val;
  Node * left, * right;
};

vector < vector < int >> zigzagLevelOrder(Node * root) {
  vector < vector < int >> result;
  if (root == NULL) {
    return result;
  }

  queue < Node * > nodesQueue;
  nodesQueue.push(root);
  bool leftToRight = true;

  while (!nodesQueue.empty()) {
    int size = nodesQueue.size();
    vector < int > row(size);
    for (int i = 0; i < size; i++) {
      Node * node = nodesQueue.front();
      nodesQueue.pop();

      ? find position to fill node's value
      int index = (leftToRight) ? i : (size - 1 - i);

      row[index] = node -> val;
      if (node -> left) {
        nodesQueue.push(node -> left);
      }
      if (node -> right) {
        nodesQueue.push(node -> right);
      }
    }
    ? after this level
    leftToRight = !leftToRight;
    result.push_back(row);
  }
  return result;
}
Node * newNode(int data) {
  Node * node = new Node;
  node -> val = data;
  node -> left = NULL;
  node -> right = NULL;
  return node;
}
int main() {
  int i, j;
  Node * root = newNode(3);
  root -> left = newNode(9);
  root -> right = newNode(20);
  root -> right -> left = newNode(15);
  root -> right -> right = newNode(7);
  vector < vector < int >> ans;
  ans = zigzagLevelOrder(root);
  cout << "Zig Zag Traversal of Binary Tree" << endl;
  for (i = 0; i < ans.size(); i++) {
    for (j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}

  */
};
// @lc code=end
