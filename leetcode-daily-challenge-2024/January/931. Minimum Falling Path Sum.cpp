class Solution
{
private:
    int minFallingPathSum(vector<vector<int>> &A, int row, int col, vector<vector<int>> &dp)
    {
        int m = A.size();
        int n = A[0].size();

        if (dp[row][col] != INT_MAX)
            return dp[row][col];

        if (row == m - 1)
            return dp[row][col] = A[row][col];

        int left = INT_MAX, right = INT_MAX;

        if (col > 0)
            left = minFallingPathSum(A, row + 1, col - 1, dp);

        int straight = minFallingPathSum(A, row + 1, col, dp);

        if (col < n - 1)
            right = minFallingPathSum(A, row + 1, col + 1, dp);

        dp[row][col] = min(left, min(straight, right)) + A[row][col];

        return dp[row][col];
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        if (n == 1 || m == 1)
            return matrix[0][0];

        int maxi = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        for (int j = 0; j < matrix.size(); j++)
        {
            maxi = min(maxi, minFallingPathSum(matrix, 0, j, dp));
        }
        return maxi;
    }
};