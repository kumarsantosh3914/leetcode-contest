class Solution
{
public:
    int dp[1001][1001] = {0};
    string longestPalindrome(string s)
    {
        int n = s.length();

        int start = 0;
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
            start = i;
            len = 1;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                start = i;
                len = 2;
            }
        }
        for (int k = 2; k < n; k++)
        {
            int i = 0, j = k;
            while (j < n)
            {
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                    start = i;
                    len = j - i + 1;
                }
                i++;
                j++;
            }
        }
        return s.substr(start, len);
    }
};