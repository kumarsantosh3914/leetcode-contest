class Solution
{
private:
    bool helper(string a, string b, map<pair<string, string>, bool> &dp)
    {
        int n = a.size();
        pair<string, string> pa = {a, b};

        if (dp.count(pa) != 0)
            return dp[pa];
        if (a == b)
            return true;

        vector<int> count(26, 0);
        for (int i = 0; i < n; i++)
        {
            count[a[i] - 'a']++;
            count[b[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (count[i])
                return false;
        }
        for (int i = 1; i < n; i++)
        {
            if (helper(a.substr(0, i), b.substr(0, i), dp) && helper(a.substr(i), b.substr(i), dp))
                return dp[pa] = true;
            if (helper(a.substr(0, i), b.substr(n - i), dp) && helper(a.substr(i), b.substr(0, n - i), dp))
                return dp[pa] = true;
        }
        return dp[pa] = false;
    }

public:
    bool isScramble(string s1, string s2)
    {
        map<pair<string, string>, bool> dp;
        return helper(s1, s2, dp);
    }
};
