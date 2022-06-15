/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    //    ? method 2

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL, *next = NULL;

        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return true;
        }

        ListNode *slow = head, *fast = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseList(slow->next);
        slow = slow->next;

        while (slow)
        {
            if (head->val != slow->val)
            {
                return false;
            }

            head = head->next;
            slow = slow->next;
        }

        return true;
    }

    // bool isPalindrome(ListNode *head)
    // {
    //     ListNode *temp = head;

    //     string s = "";

    //     while (temp)
    //     {
    //         s += temp->val;
    //         temp = temp->next;
    //     }

    //     string s1 = s;
    //     reverse(s1.begin(), s1.end());
    //     if (s == s1)
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }
};
// @lc code=end
