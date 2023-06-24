class Solution
{
public:
    int helper(int i, int diff, vector<int> &rods, int n, vector<vector<int>> &dp)
    {
        if (i == n)
        {
            if (!diff)
                return 0;
            return -1e9;
        }

        if (dp[i][5000 + diff] != -1)
            return dp[i][5000 + diff];

        int x = rods[i] + helper(i + 1, diff + rods[i], rods, n, dp);
        int y = helper(i + 1, diff - rods[i], rods, n, dp);
        int z = helper(i + 1, diff, rods, n, dp);
        return dp[i][5000 + diff] = max(max(x, y), z);
    }

    int tallestBillboard(vector<int> &rods)
    {
        int n = rods.size();
        vector<vector<int>> dp(n, vector<int>(10000, -1));
        return helper(0, 0, rods, n, dp);
    }
};