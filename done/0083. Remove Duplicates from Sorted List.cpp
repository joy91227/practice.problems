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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *current = head;
        ListNode *toCheck = head->next;
        while (toCheck != nullptr)
        {
            if (toCheck->val != current->val)
            {
                current->next = toCheck;
                current = toCheck;
            }
            else
            {
                current->next = nullptr;
            }
            toCheck = toCheck->next;
        }
        return head;
    }
};