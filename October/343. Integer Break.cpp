class Solution
{
private:
    int helper(int n, int curr, vector<vector<int>> &dp)
    {
        if (dp[n][curr] != -1)
            return dp[n][curr];
        if (curr > n)
            return helper(n, curr - 1, dp);
        else
            return max(helper(n, curr - 1, dp), curr * helper(n - curr, curr, dp));
    }

public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 2, 0);
        dp[2] = 2;
        dp[3] = 3;
        if (n <= 3)
            return dp[n] - 1;
        for (int i = 4; i < n + 1; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = max(dp[i], dp[j] * (i - j));
            }
        }
        return dp[n];
    }
};