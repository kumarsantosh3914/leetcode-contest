#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long int
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define p(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define s(x) scanf("%f", &x)
#define sl(x) scanf("%lld", &x)
#define sf(x) scanf("%lf", &x)
#define bitcount __builtin_popcountll
#define INF 1e18+9
// #define int long long
#define l "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define vv vector<vector<int> > 
#define um unordered_map<int, int>
#define m map<int,int>
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
/*
  Explanation:
  Here the trick is to find the count of no of swap, as we can easily get the array of num at a particular level using BFS traversal.
  So to evaluate the no. of count in linear complexity we need to use extra space.
  We will add the level array to a ordered map along with its index as the value and also copy it to a secondary array "u".
  Now sort array u and have the list of nums in sorted order, basically we will get to know the correct index of each element.
  Now traverse through the original level arry(t) and check if its value is it correct index or not when in sorted form.

  If not in sorted form then get original index of value which can be get from the map and swap the elements, so that t array will be in sorted form gradually.

*/
class Solution {
private:
    int helper(vector<int> &nums){
        int n = nums.size();
        m mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] = i;
        }
        sort(nums.begin(), nums.end());
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if(visited[i] || mp[nums[i]] == i)
                continue;
            int j = i; 
            int c = 0;
            while(!visited[j]){
                visited[j] = true;
                j = mp[nums[j]];
                c++;
            }
            if(c > 0)
                ans += c - 1;
        }
        return ans;
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int mini = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> arr(size);
            int i=0;
            while(size--){
                TreeNode* n = q.front();
                q.pop();
                arr[i++] = n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            mini += helper(arr);
        } 
        return mini;
    }
};