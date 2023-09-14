class Solution {
private:
    int helper(int idx, vector<string> &str, int m, int n, vector<pair<int, int>> &count, vector<vector<vector<int>>>&dp) {
        if(m < 0 || n < 0) return INT_MIN;

        if(idx == str.size() || (m == 0 && n == 0)) return 0;

        if(dp[idx][m][n] != -1) return dp[idx][m][n];

        int take = 1 + helper(idx + 1, str, m - count[idx].first, n - count[idx].second, count, dp);
        int notTake = helper(idx + 1, str, m, n, count, dp);
        return dp[idx][m][n] = max(take, notTake);
    }
public:
    int findMaxForm(vector<string>& str, int m, int n) {
        // {zero, one}
        vector<pair<int, int>> count;
        for(int i=0; i<str.size(); i++) {
            int zero = 0, one = 0;
            for(int j=0; j<str[i].size(); j++) {
                if(str[i][j] == '0') {
                    zero++;
                }
                else {
                    one++;
                }
            }
            count.push_back({zero, one});
        }
        vector<vector<vector<int>>> dp(str.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return helper(0, str, m, n, count, dp);
    }
};