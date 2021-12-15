/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 *
 * https://leetcode.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (46.34%)
 * Likes:    1693
 * Dislikes: 770
 * Total Accepted:    264.9K
 * Total Submissions: 556.7K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given the head of a singly linked list, sort the list using insertion sort,
 * and return the sorted list's head.
 *
 * The steps of the insertion sort algorithm:
 *
 *
 * Insertion sort iterates, consuming one input element each repetition and
 * growing a sorted output list.
 * At each iteration, insertion sort removes one element from the input data,
 * finds the location it belongs within the sorted list and inserts it
 * there.
 * It repeats until no input elements remain.
 *
 *
 * The following is a graphical example of the insertion sort algorithm. The
 * partially sorted list (black) initially contains only the first element in
 * the list. One element (red) is removed from the input data and inserted
 * in-place into the sorted list with each iteration.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [1, 5000].
 * -5000 <= Node.val <= 5000
 *
 *
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
    ListNode *insertionSortList(ListNode *root)
    {
        ListNode *head = NULL;

        while (root)
        {
            ListNode *temp = root;
            root = root->next;
            temp->next = NULL;

            if (head == NULL)
            {
                head = temp;
            }
            else if (head->val >= temp->val)
            {
                temp->next = head;
                head = temp;
            }
            else
            {
                ListNode *res = head;

                while (res->next)
                {
                    if (temp->val > res->val && temp->val <= res->next->val)
                    {
                        temp->next = res->next;
                        res->next = temp;
                        break;
                    }

                    res = res->next;
                }

                if (res->next == NULL)
                {
                    res->next = temp;
                }
            }
        }

        return head;
    }
};
// @lc code=end
