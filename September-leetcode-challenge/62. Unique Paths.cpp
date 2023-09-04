class Solution {
private:
    int helper(int i, int j, vector<vector<int>> &dp) {
	if(i==0 && j==0) return 1;
	if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
	//pick 
	int pick=helper(i-1, j, dp);
    //notPick
	int notPick=helper(i, j-1, dp);
	return dp[i][j] = pick+notPick;
}
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m-1, n-1, dp);
    }
};