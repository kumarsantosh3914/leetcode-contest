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
private:
    ListNode *getMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        if (head->next->next == NULL)
        {
            return head->next;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }

public:
    ListNode *middleNode(ListNode *head)
    {
        // return getMiddle(head);
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};