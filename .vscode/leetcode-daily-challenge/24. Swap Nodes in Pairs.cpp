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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyNode = new ListNode();
        ListNode *prevNode = dummyNode;
        ListNode *currNode = head;

        if (!head || !head->next)
            return head;

        while (currNode && currNode->next)
        {
            prevNode->next = currNode->next;
            currNode->next = prevNode->next->next;
            prevNode->next->next = currNode;

            prevNode = currNode;
            currNode = currNode->next;
        }
        return dummyNode->next;
    }
};
