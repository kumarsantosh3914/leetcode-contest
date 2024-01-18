class Solution
{
private:
    int solve(int n, vector<int> &dp)
    {
        // base case
        if (n == 0 || n == 1)
            return 1;
        if (n == -1)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};