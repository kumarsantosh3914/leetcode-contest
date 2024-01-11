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
    void dfs(TreeNode *root, int curMax, int curMin, int &ans)
    {
        if (!root)
            return;
        // Calculate the maximum difference between the current node's value and
        // the current minimum/maximum values encountered so far, and update the answer
        ans = max({ans, root->val - curMin, curMax - root->val});

        curMin = min(curMin, root->val);
        curMax = max(curMax, root->val);

        dfs(root->left, curMax, curMin, ans);
        dfs(root->right, curMax, curMin, ans);
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        int ans = 0;
        dfs(root, root->val, root->val, ans);
        return ans;
    }
};