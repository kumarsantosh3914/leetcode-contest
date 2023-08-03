class Solution {
private:
   void helper(int ind, vector<int> &nums, vector<vector<int>> &permute) {
       // base case
       if(ind == nums.size()) {
           permute.push_back(nums);
           return;
       }

       for(int i=ind; i<nums.size(); i++) {
           swap(nums[ind], nums[i]);
           helper(ind + 1, nums, permute);
           swap(nums[ind], nums[i]);
       }
   }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permute;
        helper(0, nums, permute);
        return permute;
    }
};