class Solution
{
private:
    int helper(vector<int> &cost, vector<int> &time, int curr, int wallRemining, vector<vector<int>> &dp)
    {
        if (wallRemining <= 0)
            return 0;

        if (curr >= cost.size())
            return 2000000000;

        if (dp[curr][wallRemining] != -1)
            return dp[curr][wallRemining];
        int notPick = helper(cost, time, curr + 1, wallRemining, dp);
        int pick = cost[curr] + helper(cost, time, curr + 1, wallRemining - time[curr] - 1, dp);

        return dp[curr][wallRemining] = min(notPick, pick);
    }

public:
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        vector<vector<int>> dp(501, vector<int>(501, -1));
        return helper(cost, time, 0, time.size(), dp);
    }
};