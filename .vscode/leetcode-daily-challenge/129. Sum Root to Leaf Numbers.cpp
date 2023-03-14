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
    void helper(TreeNode *root, int curr, int &total)
    {
        if (!root)
            return;
        // At each level our number will become 10 times greater than the number it was at the last level
        // curr = ( previous level value) * 10 + ( current root-> val )
        curr = curr * 10 + root->val;
        // If we reached the leaf node then we store the number in total
        if (!root->left && !root->right)
        {
            total += curr;
        }
        // We recursively call the function for the left and right sub trees
        helper(root->left, curr, total);
        helper(root->right, curr, total);
    }

public:
    int sumNumbers(TreeNode *root)
    {
        int total = 0;
        helper(root, 0, total);
        return total;
    }
};