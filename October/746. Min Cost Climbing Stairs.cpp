class Solution
{
private:
    int helper(vector<int> &cost, int n, vector<int> &dp)
    {
        // base case
        if (n == 0)
            return cost[0];
        if (n == 1)
            return cost[1];
        if (dp[n] != -1)
            return dp[n];

        int ans = cost[n] + min(helper(cost, n - 1, dp), helper(cost, n - 2, dp));
        return dp[n] = ans;
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int ans = min(helper(cost, n - 1, dp), helper(cost, n - 2, dp));
        return ans;
    }
};