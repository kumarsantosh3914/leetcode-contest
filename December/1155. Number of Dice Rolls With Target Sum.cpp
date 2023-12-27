#define mod 1000000007
class Solution
{
private:
    int helper(int n, int k, int target, vector<vector<int>> &dp)
    {
        // base case
        if (n >= 1 && target < 0)
            return 0;
        if (n < 1)
            return target == 0 ? 1 : 0;

        if (dp[n][target] != -1)
            return dp[n][target];

        long long cnt = 0;
        for (int i = 1; i <= k; i++)
        {
            cnt += helper(n - 1, k, target - i, dp);
        }
        return dp[n][target] = (cnt) % mod;
    }

public:
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return helper(n, k, target, dp);
    }
};