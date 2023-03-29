class Solution
{
private:
    int helper(int idx, int timeCo, vector<int> &satisfaction, vector<vector<int>> &dp)
    {
        // base case
        if (idx >= satisfaction.size())
            return 0;

        if (dp[idx][timeCo] != -1)
            return dp[idx][timeCo];

        // pick
        int pick = ((satisfaction[idx] * timeCo) + helper(idx + 1, timeCo + 1, satisfaction, dp));
        int notPick = helper(idx + 1, timeCo, satisfaction, dp);

        return dp[idx][timeCo] = max(pick, notPick);
    }

public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        // first way to solve this problem
        sort(satisfaction.begin(), satisfaction.end(), greater());
        // sort(satisfaction.begin(), satisfaction.end());
        int preSum = 0, ans = 0;
        for (int i = 0; i < satisfaction.size(); i++)
        {
            preSum += satisfaction[i];
            if (preSum < 0)
                break;
            ans += preSum;
        }
        return ans;
        // second way to solve this problem using dp
        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(0, 1, satisfaction, dp);
    }
};