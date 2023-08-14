class Solution {
private:
    int helper(int ind, vector<int> &nums, vector<int> &dp) {
        if(ind == nums.size()) return true;
        
        if(dp[ind] != -1) return dp[ind];
        
        if(ind + 1 < nums.size() && nums[ind] == nums[ind+1]) {
            if(helper(ind+2, nums, dp)) return true;
            if(ind + 2 < nums.size() && nums[ind] == nums[ind+2]) {
                if(helper(ind+3, nums, dp)) return true;
            }
        }
        if(ind + 2 < nums.size() && nums[ind] == nums[ind+1]-1 && nums[ind] == nums[ind+2]-2) {
            if(helper(ind+3, nums, dp)) return true;
        }
        return dp[ind]=false;
    }
public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(0, nums, dp);
    }
};