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
    int maxFreq = 0;
    int curFreq = 0;
    int curNum = 0;
    vector<int> ans;
    void inOrder(TreeNode *root)
    {
        if (root == NULL)
            return;

        inOrder(root->left);
        if (root->val == curNum)
            curFreq++;
        else
            curFreq = 1;
        if (curFreq > maxFreq)
        {
            ans.clear();
            maxFreq = curFreq;
            ans.push_back(root->val);
        }
        else if (curFreq == maxFreq)
        {
            ans.push_back(root->val);
        }
        curNum = root->val;
        inOrder(root->right);
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        inOrder(root);
        return ans;
    }
};