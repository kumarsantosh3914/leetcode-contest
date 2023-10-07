class Solution
{
private:
    const int mod = 1e9 + 7;
    int dp[51][51][101];
    int helper(int n, int idx, int searchCost, int maxi, int m, int k)
    {
        if (idx == n)
        {
            if (searchCost == k)
            {
                return 1;
            }
            return 0;
        }

        if (dp[idx][searchCost][maxi] != -1)
            return dp[idx][searchCost][maxi];

        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            if (i > maxi)
            {
                ans = (ans + helper(n, idx + 1, searchCost + 1, i, m, k)) % mod;
            }
            else
            {
                ans = (ans + helper(n, idx + 1, searchCost, maxi, m, k)) % mod;
            }
        }
        return dp[idx][searchCost][maxi] = ans % mod;
    }

public:
    int numOfArrays(int n, int m, int k)
    {
        memset(dp, -1, sizeof(dp));
        return helper(n, 0, 0, 0, m, k);
    }
};