class Solution
{
public:
    int minOperations(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] - '0' != i % 2)
            {
                ans++;
            }
        }
        int n = s.size();
        return min(ans, (n - ans));
    }
};