class Solution
{
public:
    int countHomogenous(string s)
    {
        const int mod = 1e9 + 7;
        int l = 0;
        int ans = 0;
        while (l < s.size())
        {
            int r = l;
            while (r < s.size() && s[l] == s[r])
            {
                r++;
            }
            long long len = r - l;
            ans = (ans + len * (len + 1) / 2) % mod;
            l = r;
        }
        return ans;
    }
};