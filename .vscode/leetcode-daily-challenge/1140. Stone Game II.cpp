class Solution
{
private:
    int helper(int i, int M, vector<int> &piles, vector<vector<int>> &dp)
    {
        // base case
        if (i >= piles.size())
            return 0;
        if (dp[i][M] != -1)
            return dp[i][M];

        int total = 0, ans = INT_MIN;
        for (int j = 0; j < 2 * M; j++)
        {
            if (i + j < piles.size())
                total += piles[i + j];
            ans = max(ans, total - helper(i + j + 1, max(M, j + 1), piles, dp));
        }
        return dp[i][M] = ans;
    }

public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        int sum = 0;
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        for (auto it : piles)
        {
            sum += it;
        }
        int difference = helper(0, 1, piles, dp);
        return (sum + difference) / 2;
    }
};
