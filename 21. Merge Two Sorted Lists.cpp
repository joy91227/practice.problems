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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        }
        ListNode *head;
        if (l1->val <= l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }
        ListNode *current = head;
        while (l1 && l2)
        {
            int l1Val = l1->val;
            int l2Val = l2->val;
            if (l1Val <= l2Val)
            {
                // advance l1
                current->next = l1;
                current = l1;
                l1 = l1->next;
            }
            else
            {
                // advance l2
                current->next = l2;
                current = l2;
                l2 = l2->next;
            }
        }
        // check for remainders
        if (l1 && !l2)
        {
            current->next = l1;
        }
        if (!l1 && l2)
        {
            current->next = l2;
        }
        return head;
    }
};