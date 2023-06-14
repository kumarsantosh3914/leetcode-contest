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
    void inOrder(TreeNode *root, vector<int> &nums)
    {
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        vector<int> nums;
        inOrder(root, nums);
        int ans = INT_MAX;
        for (int i = 1; i < nums.size(); i++)
        {
            int diff = nums[i] - nums[i - 1];
            ans = min(ans, diff);
        }
        return ans;
    }
};