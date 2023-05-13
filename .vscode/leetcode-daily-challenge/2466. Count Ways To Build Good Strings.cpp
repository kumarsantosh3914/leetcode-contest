#define mod 1000000007
class Solution
{
private:
    // vector<int> dp;
    int helper(int len, int zero, int one, vector<int> &dp)
    {
        // if target is 0 that means this target can be made so return 1
        if (len == 0)
            return 1;
        // target < 0 can not be made
        if (len < 0)
            return 0;
        int &result = dp[len];

        if (result != -1)
            return dp[len];
        result = (helper(len - zero, zero, one, dp) + helper(len - one, zero, one, dp)) % mod;
        return result;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        long long int ans = 0;
        vector<int> dp(high + 1, -1);
        for (int i = low; i <= high; i++)
        {
            ans = (ans + helper(i, zero, one, dp)) % mod;
        }
        return ans;
    }
};
