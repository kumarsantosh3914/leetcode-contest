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
    void reorderList(ListNode *head)
    {
        stack<ListNode *> st;
        ListNode *temp = head;
        int size = 0;

        while (temp != NULL)
        {
            st.push(temp);
            size++;
            temp = temp->next;
        }

        temp = head;
        // Between every two nodes insert the one in the top of the stack
        for (int i = 0; i < size / 2; i++)
        {
            ListNode *ele = st.top();
            st.pop();
            ele->next = temp->next;
            temp->next = ele;
            temp = temp->next->next;
        }
        temp->next = NULL;
    }
};

/**
- stack = 1 2
- size = 4
- temp = head = 1
- (1 - 4 - 2 - 3) which is answer
*/