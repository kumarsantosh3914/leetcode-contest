class Solution
{
private:
    int helper(int idx, vector<int> &jobDifficulty, int d, vector<vector<int>> &dp)
    {
        if (d == 1)
        {
            int maxi = jobDifficulty[idx];
            for (int i = idx; i < jobDifficulty.size(); i++)
            {
                maxi = max(maxi, jobDifficulty[i]);
            }
            return maxi;
        }

        if (dp[idx][d] != -1)
            return dp[idx][d];

        int maxi = INT_MIN;
        int ans = INT_MAX;
        for (int i = idx; i <= jobDifficulty.size() - d; i++)
        {
            maxi = max(maxi, jobDifficulty[i]);
            ans = min(ans, maxi + helper(i + 1, jobDifficulty, d - 1, dp));
        }
        return dp[idx][d] = ans;
    }

public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        if (n < d)
            return -1;
        vector<vector<int>> dp(n, vector<int>(d + 1, -1));
        return helper(0, jobDifficulty, d, dp);
    }
};