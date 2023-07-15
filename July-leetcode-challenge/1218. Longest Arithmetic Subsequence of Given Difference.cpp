class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int maxiLen = 0;

        for(int i=0; i<arr.size(); i++) {
            int temp = arr[i] - difference;
            int tempAns = 0;
            
            if(dp.count(temp)) tempAns = dp[temp];
            dp[arr[i]] = 1 + tempAns;
            maxiLen = max(maxiLen, dp[arr[i]]); 
        }
        return maxiLen;
    }
};