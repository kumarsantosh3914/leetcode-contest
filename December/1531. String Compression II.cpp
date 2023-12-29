class Solution
{
    const static int N = 127;
    int dp[N][N];
    string str;
    int n;

    // get length of digit
    inline int xs(int x) { return x == 1 ? 0 : x < 10 ? 1
                                           : x < 100  ? 2
                                                      : 3; }

    int solve(int left, int k)
    {
        if (k < 0)
            return N; // invalid, return INF
        if (left >= n or n - left <= k)
            return 0; // empty

        int &res = dp[left][k];
        if (res != -1)
            return res;
        res = N;

        int cnt[26] = {0};
        for (int j = left, most = 0; j < n; j++)
        {
            most = max(most, ++cnt[str[j] - 'a']); // most = max(count(s[left:j])
            res = min(res, 1 + xs(most) + solve(j + 1, k - (j - left + 1 - most)));
        }
        return res;
    }

public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        memset(dp, -1, sizeof(dp));
        str = s;
        n = s.size();
        return solve(0, k);
    }
};