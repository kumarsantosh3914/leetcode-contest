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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int len = 0;
        while(curr) {
            len++;
            curr = curr->next;
        }

        int eachBucketNode = len / k;
        int reminderNodes = len % k;
        vector<ListNode*> parts(k, NULL);
        curr = head;
        ListNode* prev = NULL;
        for(int i=0; i<k; i++) {
            parts[i] = curr;
            for(int count=1; count<= eachBucketNode + (reminderNodes > 0 ? 1 : 0); count++) {
                prev = curr;
                curr = curr->next;
            } 
            if(prev != NULL) prev->next = NULL;
            reminderNodes--;
        }
        return parts;
    }
};