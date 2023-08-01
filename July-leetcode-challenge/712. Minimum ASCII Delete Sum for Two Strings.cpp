class Solution {
private:
    int helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return dp[i][j] = s1[i] + helper(i - 1, j - 1, s1, s2, dp);
        return dp[i][j] = max(helper(i - 1, j, s1, s2, dp), helper(i, j - 1, s1, s2, dp));
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int sum1 = 0, sum2 = 0;
        for(auto &it: s1) {
            sum1 += it;
        }

        for(auto &it: s2) {
            sum2 += it;
        }
        vector<vector<int>> dp(s1.size(), vector<int> (s2.size() + 1, -1));
        return (sum1 + sum2) - 2 * helper(s1.size() - 1, s2.size() - 1, s1, s2, dp);
    }
};
