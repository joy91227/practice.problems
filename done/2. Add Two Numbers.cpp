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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode();
        ListNode *tracker = new ListNode();
        ListNode *current1 = l1;
        ListNode *prev1;
        ListNode *current2 = l2;
        int carry = 0;
        while (current1 && current2)
        {
            int sum = current1->val + current2->val + carry;
            current1->val = sum % 10;
            carry = sum >= 10 ? 1 : 0;
            prev1 = current1;
            current1 = current1->next;
            current2 = current2->next;
        }
        while (current1)
        {
            // l1 is longer than l2
            int sum = (current1->val + carry);
            current1->val = sum % 10;
            carry = sum >= 10 ? 1 : 0;
            prev1 = current1;
            current1 = current1->next;
        }
        while (current2)
        {
            // l2 is longer than l1
            int sum = (current2->val + carry);
            current1 = new ListNode(sum % 10);
            carry = sum >= 10 ? 1 : 0;
            current2 = current2->next;
            prev1->next = current1;
            prev1 = current1;
        }
        // check for last digit
        if (carry)
        {
            prev1->next = new ListNode(carry);
        }
        return l1;
    }
};