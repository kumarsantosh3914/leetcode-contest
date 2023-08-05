class Solution {
private:
    int helper(int i, string s, set<string>&wordDict, vector<int> &dp) {
        if(i==s.size()) return 1;
        string temp;
        if(dp[i] != -1) return dp[i];
        for(int j=i; j<s.size(); j++) {
            temp += s[j];
            if(wordDict.find(temp) != wordDict.end()) {
                if(helper(j+1,s,wordDict, dp))
                return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        vector<int> dp(s.size(), -1);
        for(auto it:wordDict) st.insert(it);
        return helper(0, s, st, dp);
    }
};