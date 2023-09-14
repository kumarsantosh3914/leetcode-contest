class Solution {
private:
    int findSquare(vector<vector<char>>& matrix, int i, int j, vector<vector<int>> &dp) {
        if(i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] == '0') {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int sum = 1 + min(findSquare(matrix, i + 1, j + 1, dp), min(findSquare(matrix, i + 1, j, dp), findSquare(matrix, i, j + 1, dp)));
        return dp[i][j] = sum;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        if(matrix.size() == 0) return 0;

        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        int maxi = 0, currMaxi = 0;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                currMaxi = findSquare(matrix, i, j, dp);
                if(maxi < currMaxi) {
                    maxi = currMaxi;
                }
            }
        }
        return maxi * maxi;
    }
};