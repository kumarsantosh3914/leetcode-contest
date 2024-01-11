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
    int dfs(TreeNode *root, int start, int &ans)
    {
        // base case
        if (!root)
            return 0;
        int x = dfs(root->left, start, ans);
        int y = dfs(root->right, start, ans);

        if (root->val == start)
        {
            ans = max(ans, max(x, y));
            return -1;
        }
        if (x >= 0 && y >= 0)
        {
            return max(x, y) + 1;
        }

        ans = max(ans, abs(x) + abs(y));
        return min(x, y) - 1;
    }

    unordered_map<int, vector<int>> adj;
    void createGraph(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        q.push({root, -1});
        while (q.size())
        {
            auto [node, parent] = q.front();
            q.pop();
            if (parent != -1)
            {
                adj[parent].push_back(root->val);
                adj[root->val].push_back(parent);
            }
            if (root->left)
            {
                q.push({root->left, root->val});
            }
            if (root->right)
            {
                q.push({root->right, root->val});
            }
        }
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        // int res = 0;
        // int k = dfs(root, start, res);
        // return res;
        createGraph(root);

        unordered_map<int, bool> seen;
        queue<int> q;
        q.push(start);
        seen[start] = true;
        int time = 0;
        while (!q.empty())
        {
            int n = q.size();
            time++;
            while (n--)
            {
                auto node = q.front();
                q.pop();
                for (auto &it : adj[node])
                {
                    if (!seen[it])
                    {
                        q.push(it);
                        seen[it] = true;
                    }
                }
            }
        }
        return time - 1;
    }
};