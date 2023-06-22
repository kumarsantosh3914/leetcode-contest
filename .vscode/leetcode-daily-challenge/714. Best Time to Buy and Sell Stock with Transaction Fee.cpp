class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<long>> dp(prices.size() + 1, vector<long>(2, -1));
        int n = prices.size();
        dp[n][0] = dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                long profit = 0;
                if (buy)
                {
                    profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                }
                else
                {
                    profit = max((prices[i] - fee) + dp[i + 1][1], dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};