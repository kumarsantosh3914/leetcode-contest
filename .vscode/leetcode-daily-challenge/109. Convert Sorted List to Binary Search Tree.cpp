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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    TreeNode *constructBST(ListNode *start, ListNode *end)
    {
        if (start == end)
            return NULL;
        ListNode *slow = start, *fast = start;
        while (fast != end && fast->next != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = constructBST(start, slow);
        root->right = constructBST(slow->next, end);
        return root;
    }

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
        {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        return constructBST(head, NULL);
    }
};
