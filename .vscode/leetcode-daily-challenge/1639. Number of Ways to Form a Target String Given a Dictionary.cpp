#define ll long long
#define mod 1000000007
class Solution
{
private:
    ll dp[1001][1001];
    ll helper(int i, string &target, vector<vector<int>> &temp, int j)
    {
        if (i == target.size())
            return 1;
        if (j == temp.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        ll ans = 0;
        ans += helper(i, target, temp, j + 1);
        ans %= mod;
        ans += (temp[j][target[i] - 'a'] * helper(i + 1, target, temp, j + 1)) % mod;
        return dp[i][j] = ans % mod;
    }

public:
    int numWays(vector<string> &words, string target)
    {
        int n = words[0].size();
        vector<vector<int>> temp(n, vector<int>(26, 0));
        for (auto it : words)
        {
            for (int i = 0; i < it.size(); i++)
            {
                temp[i][it[i] - 'a']++;
            }
        }
        memset(dp, -1, sizeof dp);
        return helper(0, target, temp, 0);
    }
};