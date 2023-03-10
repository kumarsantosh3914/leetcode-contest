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
    vector<int> nodes;

public:
    Solution(ListNode *head)
    {
        while (head != NULL)
        {
            nodes.push_back(head->val);
            head = head->next;
        }
    }

    int getRandom()
    {
        int i = rand() % this->nodes.size();
        return this->nodes[i];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */