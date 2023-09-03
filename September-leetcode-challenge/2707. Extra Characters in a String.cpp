class Solution {
private:
    int helper(int idx, string &s, unordered_set<string> &st, vector<int> &dp) {
        if(idx >= s.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int ans = INT_MAX;
        string currString = "";
        for(int i=idx; i<s.size(); i++) {
            currString.push_back(s[i]);
            int currExtra = (st.find(currString) == st.end()) ? currString.size() : 0;
            int nextExtra = helper(i + 1, s, st, dp);

            int totalExtra = currExtra + nextExtra;
            ans = min(ans, totalExtra);
        } 
        return dp[idx] = ans;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        vector<int> dp(s.size() + 1, -1);
        return helper(0, s, st, dp);
    }
};