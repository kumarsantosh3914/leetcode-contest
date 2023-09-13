class Solution {
private:
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        // base case
        if(i == n - 1 && j == m - 1) return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];
        
        if(i == n - 1) {
          return dp[i][j] = grid[i][j] + solve(i, j + 1, n, m, grid, dp);
        }

        else if(j == m - 1) {
          return dp[i][j] = grid[i][j] + solve(i + 1, j, n, m, grid, dp);
        }
        else {
          return dp[i][j] = grid[i][j] + min(solve(i, j + 1, n, m, grid, dp), solve(i + 1, j, n, m, grid, dp));
        }
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(0, 0, n, m, grid, dp);
    }
};