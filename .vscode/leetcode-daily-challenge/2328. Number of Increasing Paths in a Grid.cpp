class Solution
{
public:
    int m = 0, n = 0;
    vector<vector<int>> grid;
    long long mod = 1000000000 + 7;

    long long dp[1000][1000];

    long long int solve(int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int left = 0, right = 0, down = 0, up = 0;
        if (i + 1 < m && grid[i + 1][j] > grid[i][j])
            down = 1 + solve(i + 1, j);
        if (i - 1 >= 0 && grid[i - 1][j] > grid[i][j])
            up = 1 + solve(i - 1, j);
        if (j + 1 < n && grid[i][j + 1] > grid[i][j])
            right = 1 + solve(i, j + 1);
        if (j - 1 >= 0 && grid[i][j - 1] > grid[i][j])
            left = 1 + solve(i, j - 1);

        return dp[i][j] = (left + right + down + up) % (this->mod);
    }

public:
    int countPaths(vector<vector<int>> &grid)
    {
        this->m = grid.size();
        this->n = grid[0].size();
        this->grid = grid;

        memset(dp, -1, sizeof(dp));

        long long int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans += 1 + solve(i, j);
            }
        }
        return (ans) % (this->mod);
    }
};