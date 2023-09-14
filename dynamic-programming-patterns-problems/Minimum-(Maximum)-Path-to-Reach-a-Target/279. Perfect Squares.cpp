class Solution {
private:
    int helper(int n, vector<int> &dp) {
        //out of bound
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        //trying to substract all possible perfect squares and take min one
        int mini = INT_MAX;
        //got till square root of n because if we substract
        //bigger value from n then it will become minus so don't do that
        for(int i=1; i<=sqrt(n); i++) {
            int cur = i * i;
            int steps = 1 + helper(n - cur, dp);
            mini = min(mini, steps);
        }
        return dp[n] = mini;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};