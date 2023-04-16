class Solution
{
public:
    int dp[1001][2001];
    int helper(vector<vector<int>> &piles, int k, int i)
    {
        // base case
        if (i >= piles.size())
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        int maxi = 0;
        maxi = max(maxi, helper(piles, k, i + 1));
        for (int j = 0; j < piles[i].size(); j++)
        {
            if (j + 1 <= k)
                maxi = max(maxi, piles[i][j] + helper(piles, k - j - 1, i + 1));
            else
                break;
        }
        return dp[i][k] = maxi;
    }
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        for (int i = 0; i < piles.size(); i++)
        {
            for (int j = 1; j < piles[i].size(); j++)
            {
                piles[i][j] = piles[i][j] + piles[i][j - 1];
            }
        }
        memset(dp, -1, sizeof dp);
        return helper(piles, k, 0);
    }
};