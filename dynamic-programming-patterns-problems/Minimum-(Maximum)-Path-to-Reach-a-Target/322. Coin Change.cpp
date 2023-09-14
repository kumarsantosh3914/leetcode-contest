class Solution {
private:
    int helper(int idx, vector<int>& coins, int amount, vector<vector<int>> &dp) {
        //base case
        if(idx >= coins.size() || amount <= 0) {
            return (amount == 0) ? 0 : INT_MAX - 1;
        }

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int ans = -1;
        if(coins[idx] > amount) {
            int notTake = 0 +  helper(idx + 1, coins, amount - 0, dp);
            ans = notTake;
        }
        else {
            int take = 1 + helper(idx + 0, coins, amount - coins[idx], dp);
            int notTake = 0 + helper(idx + 1, coins, amount - 0, dp);
            ans = min(take, notTake);
        }
        return dp[idx][amount] = ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, -1));
        int ans = helper(0, coins, amount, dp);
        return (ans == INT_MAX - 1) ? -1 : ans;
    }
};