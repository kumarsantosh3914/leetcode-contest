class Solution
{
public:
    int minSteps(string s, string t)
    {
        map<char, int> mp;
        for (auto a : s)
            mp[a]++;
        for (auto a : t)
            mp[a]--;
        int ans = 0;
        for (auto a : mp)
            ans += abs(a.second);
        return ans / 2;
    }
};