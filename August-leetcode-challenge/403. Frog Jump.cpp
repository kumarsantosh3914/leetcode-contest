class Solution {
private:
    unordered_map<int, int> mp;
private:
    bool helper(int idx, int prevJump, vector<int> &stones, vector<vector<int>> &dp) {
        if(idx == stones.size()- 1) return true;

        if(dp[idx][prevJump] != -1) return dp[idx][prevJump];

        bool ans = false;
        for(int nextJump=prevJump - 1; nextJump<=prevJump + 1; nextJump++) {
            if(nextJump > 0) {
                int nextStone = stones[idx] + nextJump;
                if(mp.find(nextStone) != mp.end()) {
                    ans = ans || helper(mp[nextStone], nextJump, stones, dp);
                }
            }
        }
        return dp[idx][prevJump] = ans;
    }
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;

        for(int i=0; i<stones.size(); i++) {
            mp[stones[i]] = i;
        }
        vector<vector<int>> dp(stones.size() + 1, vector<int> (stones.size() + 1, -1));
        return helper(0, 0, stones, dp);
    }
};