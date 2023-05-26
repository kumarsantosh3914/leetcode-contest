class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        if (k == 0)
            return 1.0;
        if (n >= k - 1 + maxPts)
            return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double probability = 0.0;
        double windSum = 1.0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = windSum / maxPts;
            if (i < k)
            {
                windSum += dp[i];
            }
            else
            {
                probability += dp[i];
            }
            if (i >= maxPts)
                windSum -= dp[i - maxPts];
        }
        return probability;
    }
};