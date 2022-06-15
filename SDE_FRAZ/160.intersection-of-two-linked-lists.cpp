/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *temp1 = headA, *temp2 = headB;

        if (temp1 == NULL || temp2 == NULL)
        {
            return NULL;
        }

        while (temp1 != NULL && temp2 != NULL && temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;

            if (temp1 == temp2)
            {
                return temp2;
            }

            if (temp1 == NULL)
            {
                temp1 = headB;
            }

            if (temp2 == NULL)
            {
                temp2 = headA;
            }
        }

        return temp1;
    }
};
// @lc code=end
