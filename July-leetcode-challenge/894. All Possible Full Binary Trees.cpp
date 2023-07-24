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
class Solution {
public:
    // global map
    unordered_map<int, vector<TreeNode *>> memo;
    
    // recursion is very lengthy: memorization can help a little bit
    vector<TreeNode *> allPossibleFBT(int n) {
        // vector that stores ans
        vector<TreeNode *> ans;
        // base case
        if (n < 1 || n % 2 == 0) {
            // if n is less than 1 or a multiple of 2: cannot have a FULL binary tree
            return ans;
        }
        if (memo.find(n) != memo.end()) {
            // memo map has something
            return memo[n];
        }
        if (n == 1) {
            // if n is eql to 1 simply return
            ans.push_back(new TreeNode(0));
            memo[1] = ans;
            return ans;
        }

        for (int i = 1; i < n; i += 2) {
            vector<TreeNode *> left = allPossibleFBT(i);
            vector<TreeNode *> right = allPossibleFBT(n - 1 - i);
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode *root = new TreeNode(0);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        memo[n] = ans;  // memorize the ans for this integer
        return ans;
    }
};