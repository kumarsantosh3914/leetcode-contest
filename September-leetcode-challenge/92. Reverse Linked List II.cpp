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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;
        
        ListNode dummyHead(INT_MIN);
        dummyHead.next = head;
        
        auto* nodeBeforeReversedSublist = &dummyHead;
        int pos = 1;
        while(pos < left) {
            nodeBeforeReversedSublist = nodeBeforeReversedSublist->next;
            pos++;
        }
        
        auto* sublistWorkingPtr = nodeBeforeReversedSublist->next;
        while(left < right) {
            // cut the new node out
            auto* nodeComingToSublistFront = sublistWorkingPtr->next;
            sublistWorkingPtr->next = nodeComingToSublistFront->next;
            
            // pasting it at the front
            nodeComingToSublistFront->next = nodeBeforeReversedSublist->next;
            nodeBeforeReversedSublist->next = nodeComingToSublistFront;
            left++;
        }
        return dummyHead.next;
    }
};