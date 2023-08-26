class Solution {
private:
    int helper(int idx, int prev, vector<vector<int>> &pairs, vector<vector<int>> &dp) {
        if(idx == pairs.size()) return 0;

        if(dp[idx][prev + 1] != -1) return dp[idx][prev + 1];

        int take = INT_MIN;
        if(prev == -1 || pairs[prev][1] < pairs[idx][0]) {
            take = 1 + helper(idx + 1, idx, pairs, dp);
        } 

        int notTake = helper(idx + 1, prev, pairs, dp);
        return dp[idx][prev + 1] = max(take, notTake);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs), end(pairs));
        vector<vector<int>> dp(pairs.size(), vector<int> (pairs.size() + 1, -1));
        return helper(0, -1, pairs, dp);
    }
};