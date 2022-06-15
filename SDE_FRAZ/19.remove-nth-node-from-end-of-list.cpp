/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = new ListNode();

        temp->next = head;
        ListNode *fast = temp, *slow = temp;

        for (int i = 1; i <= n; i++)
        {
            fast = fast->next;
        }

        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return temp->next;
    }
};
// @lc code=end
