/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *iter = head, *front = head;

        // ? first made the copy linked list nodes adjacent to the orignal nodes

        while (iter != NULL)
        {
            front = iter->next;
            Node *copy = new Node(iter->val);

            iter->next = copy;
            copy->next = front;

            iter = front;
        }

        // ? assign random pointer to the copy nodes

        iter = head;
        while (iter != NULL)
        {
            if (iter->random != NULL)
            {
                iter->next->random = iter->random->next;
            }

            iter = iter->next->next;
        }

        // ? restore the orignal lists and extract the copy

        iter = head;
        Node *pseudo = new Node(0);

        Node *copy = pseudo;

        while (iter != NULL)
        {
            front = iter->next->next;

            copy->next = iter->next;
            iter->next = front;

            copy = copy->next;
            iter = front;
        }

        return pseudo->next;
    }
};
// @lc code=end
