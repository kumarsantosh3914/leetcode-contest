class Solution
{
private:
    int helper(string &s, int index, vector<int> &dp)
    {
        if (index == s.size())
            return 1;

        if (s[index] == '0')
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int way1 = helper(s, index + 1, dp);
        int way2 = 0;
        if (index + 1 < s.size() && (s[index] == '1' || s[index] == '2' && s[index + 1] <= '6'))
        {
            way2 = helper(s, index + 2, dp);
        }
        return dp[index] = way1 + way2;
    }

public:
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 1, -1);
        return helper(s, 0, dp);
    }
};