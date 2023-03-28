class Solution
{
private:
    int helper(int idx, vector<int> &days, vector<int> &costs, vector<int> &dp)
    {
        // base case
        if (idx >= days.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        // 1-day pass cost
        int dayCost = costs[0] + helper(idx + 1, days, costs, dp);

        // 7-day pass cost
        int i;
        for (i = idx; i < days.size() && days[i] < days[idx] + 7; i++)
            ;
        int weekCost = costs[1] + helper(i, days, costs, dp);

        // 30-day pass cost
        for (i = idx; i < days.size() && days[i] < days[idx] + 30; i++)
            ;
        int monthCost = costs[2] + helper(i, days, costs, dp);

        // return minimum of them
        return dp[idx] = min(dayCost, min(weekCost, monthCost));
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(days.size(), -1);
        return helper(0, days, costs, dp);
    }
};
