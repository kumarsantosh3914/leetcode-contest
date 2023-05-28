class Solution
{
private:
    int dp[500001];
    int helper(vector<int> &s, int i)
    {
        if (i >= s.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        else
        {
            int ans = INT_MIN;
            ans = max(ans, s[i] - helper(s, i + 1));
            if (i + 1 < s.size())
                ans = max(ans, s[i] + s[i + 1] - helper(s, i + 2));
            if (i + 2 < s.size())
                ans = max(ans, s[i] + s[i + 1] + s[i + 2] - helper(s, i + 3));
            return dp[i] = ans;
        }
    }

public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        for (int i = 0; i < stoneValue.size(); i++)
        {
            dp[i] = -1;
        }
        int alice = helper(stoneValue, 0);
        if (alice > 0)
            return "Alice";
        if (alice == 0)
            return "Tie";
        return "Bob";
    }
};