class Solution
{
private:
    int mod = 1000000007;
    int dp[55][55][55];
    long helper(int i, int j, int m, int n, int move)
    {
        // base case
        if (i >= m || i < 0 || j >= n || j < 0)
            return 1;

        if (move <= 0)
            return 0;
        if (dp[i][j][move] != -1)
            return dp[i][j][move];

        long ans = 0;
        ans += helper(i + 1, j, m, n, move - 1);
        ans += helper(i - 1, j, m, n, move - 1);
        ans += helper(i, j + 1, m, n, move - 1);
        ans += helper(i, j - 1, m, n, move - 1);

        return dp[i][j][move] = ans % mod;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        return helper(startRow, startColumn, m, n, maxMove) % mod;
    }
};