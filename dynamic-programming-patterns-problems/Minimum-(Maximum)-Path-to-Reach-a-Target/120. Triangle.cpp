class Solution {
private:
    int solve(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
      // base case
      if(i == n - 1) return triangle[n - 1][j];

      if(dp[i][j] != -1) return dp[i][j];

      int down = triangle[i][j] + solve(i + 1, j, n, triangle, dp);
      int diagonal = triangle[i][j] + solve(i + 1, j + 1, n, triangle, dp);

      return dp[i][j] = min(down, diagonal);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, n, triangle, dp);
    }
};