class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); // dp[i] stores the length of the longest increasing subsequence ending at index i
        vector<int> count(n, 1); // count[i] stores the number of longest increasing subsequences ending at index i
        int maxi = 1; // stores the maximum length of increasing subsequence

        for(int i=0; i<=n-1; i++) {
            for(int prevIdx=0; prevIdx<=i - 1; prevIdx++) {
                if(nums[prevIdx] < nums[i] && dp[prevIdx] + 1 > dp[i]) {
                    dp[i] = dp[prevIdx] + 1; // update the length of the increasing subsequence ending at index i
                    count[i] = count[prevIdx]; // inherit the number of subsequences from the previous index
                }
                else if(nums[prevIdx] < nums[i] && dp[prevIdx] + 1 == dp[i]) {
                    count[i] = count[i] + count[prevIdx]; // add the number of subsequences from the previous index to the count
                }
            }
            maxi = max(maxi, dp[i]); // update the maximum length of increasing subsequence
        }
        int ans = 0;
        for(int i=0; i<=n - 1; i++) {
            if(dp[i] == maxi) {
                ans += count[i]; // add the count of subsequences ending at index i to the answer
            }
        }
        return ans;
    }
};