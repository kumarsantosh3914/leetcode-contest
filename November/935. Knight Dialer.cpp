class Solution
{
private:
    int dp[5001][10];
    vector<vector<int>> adj = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}};
    const int mod = 1e9 + 7;
    int helper(int n, int cell)
    {
        if (n == 0)
        {
            return 1;
        }

        if (dp[n][cell] != -1)
            return dp[n][cell];

        int ans = 0;
        for (auto &it : adj[cell])
        {
            ans = (ans + helper(n - 1, it)) % mod;
        }
        return dp[n][cell] = ans;
    }

public:
    int knightDialer(int n)
    {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 0; i <= 9; i++)
        {
            ans = (ans + helper(n - 1, i)) % mod;
        }
        return ans;
    }
};