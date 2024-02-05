class Solution
{
private:
    int helper(int idx, int k, vector<int> &arr, vector<int> &dp)
    {
        int n = arr.size();
        if (idx >= n)
        {
            return 0;
        }

        if (dp[idx] != -1)
            return dp[idx];

        int maxSum = 0, maxEle = 0;
        for (int i = idx; i < min(n, idx + k); i++)
        {
            maxEle = max(maxEle, arr[i]);
            maxSum = max(maxSum, maxEle * (i - idx + 1) + helper(i + 1, k, arr, dp));
        }
        return dp[idx] = maxSum;
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return helper(0, k, arr, dp);
    }
};