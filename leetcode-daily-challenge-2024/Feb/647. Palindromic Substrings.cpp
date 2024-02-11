class Solution
{
private:
    bool check(int i, int j, string &s, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
        {
            return check(i + 1, j - 1, s, dp);
        }

        return dp[i][j] = false;
    }

public:
    int countSubstrings(string s)
    {
        int cnt = 0;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (check(i, j, s, dp))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};