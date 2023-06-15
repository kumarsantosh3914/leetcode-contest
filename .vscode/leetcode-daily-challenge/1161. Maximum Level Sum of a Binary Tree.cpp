class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        int sum = INT_MIN, ans, l = 1;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size())
        {
            int n = q.size(), s = 0;
            while (n--)
            {
                TreeNode *temp = q.front();
                q.pop();
                s += temp->val;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            if (s > sum)
                sum = s, ans = l;
            l++;
        }
        return ans;
    }
};