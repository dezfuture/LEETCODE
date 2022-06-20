/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> res;
        ListNode *temp = head;

        while (temp != NULL)
        {
            res.push_back(temp->val);
            temp = temp->next;
        }

        int n = res.size();
        vector<int> ans(n, 0);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && res[i] > res[s.top()])
            {
                int k = s.top();
                ans[k] = res[i];
                s.pop();
            }

            s.push(i);
        }

        return ans;
    }
};
// @lc code=end
