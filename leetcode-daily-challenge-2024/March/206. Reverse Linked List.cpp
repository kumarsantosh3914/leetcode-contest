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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *fawared = NULL;
        while (curr != NULL)
        {
            fawared = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fawared;
        }
        return prev;
    }
};