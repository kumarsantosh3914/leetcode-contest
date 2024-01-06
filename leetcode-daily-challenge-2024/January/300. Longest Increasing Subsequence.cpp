class Solution
{
private:
    long f(int ind, int prevInd, vector<int> &nums, vector<vector<int>> &dp)
    {
        // base case
        if (ind == nums.size())
            return 0;

        if (dp[ind][prevInd + 1] != -1)
            return dp[ind][prevInd + 1];
        // Not pick
        long len = 0 + f(ind + 1, prevInd, nums, dp);
        // pick
        if (prevInd == -1 || nums[ind] > nums[prevInd])
        {
            len = max(len, 1 + f(ind + 1, ind, nums, dp));
        }
        return dp[ind][prevInd + 1] = len;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return f(0, -1, nums, dp);
    }
};