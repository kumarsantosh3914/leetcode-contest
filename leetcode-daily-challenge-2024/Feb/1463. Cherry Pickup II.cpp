class Solution
{
private:
    int dp[71][71][71];
    int helper(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid)
    {
        if (j1 < 0 || j2 < 0 || j1 == m || j2 == m)
        {
            return INT_MIN;
        }
        if (i == n)
            return 0;
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        else
        {
            int ans = grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
            int op = 0;
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    op = max(op, helper(i + 1, j1 + x, j2 + y, n, m, grid));
                }
            }
            return dp[i][j1][j2] = ans + op;
        }
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        memset(dp, -1, sizeof dp);
        return helper(0, 0, m - 1, n, m, grid);
    }
};