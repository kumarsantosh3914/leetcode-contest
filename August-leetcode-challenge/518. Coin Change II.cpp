class Solution {
public:
    int helper(int amount, vector<int> &coins, int i, vector<vector<int>> &dp) {
        //base case
        if(amount==0) return 1;
        if(amount<0 || i==coins.size()) return 0;
        if(dp[amount][i]!=-1) return dp[amount][i];

        int ans=0;
        ans+=helper(amount-coins[i], coins, i, dp);
        ans+=helper(amount, coins, i+1, dp);
        return dp[amount][i]=ans;
    }
    int change(int amount, vector<int>& coins) {
        // memset(dp, -1, sizeof dp);
        vector<vector<int>> dp(amount + 1, vector<int> (coins.size(), -1));
        return helper(amount, coins, 0, dp);
    }
};