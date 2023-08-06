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
private:
   vector<TreeNode*> buildTree(int start, int end) {
	vector<TreeNode*> ans;
        
    // If start > end, then subtree will be empty so add NULL in the ans and return it.
    if(start > end) {
		ans.push_back(NULL);
        return ans;
    }

    // Iterate through all values from start to end to construct left and right subtree recursively
	for(int i = start; i <= end; ++i) {
		vector<TreeNode*> leftSubTree = buildTree(start, i - 1);    // Construct left subtree
        vector<TreeNode*> rightSubTree = buildTree(i + 1, end);     // Construct right subtree
            
		// loop through all left and right subtrees and connect them to ith root  
		for(int j = 0; j < leftSubTree.size(); j++) {
			for(int k = 0; k < rightSubTree.size(); k++) {
				TreeNode* root = new TreeNode(i);   // Create root with value i
				root->left = leftSubTree[j];   // Connect left subtree rooted at leftSubTree[j]
                root->right = rightSubTree[k];   // Connect right subtree rooted at rightSubTree[k]
				ans.push_back(root);    // Add this tree(rooted at i) to ans data-structure
			}
		}
    } 
	return ans;
}
public:
    vector<TreeNode*> generateTrees(int n) {
        return buildTree(1, n);
    }
};