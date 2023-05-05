class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int ans = 0, st = 0, e = 0, cnt = 0, l = 0;
        unordered_set<char> d = {'a', 'e', 'i', 'o', 'u'};
        while (e < s.size())
        {
            if (l == k)
            {
                if (d.find(s[st++]) != d.end())
                    cnt--;
                if (d.find(s[e++]) != d.end())
                    cnt++;
            }
            else
            {
                if (d.find(s[e++]) != d.end())
                    cnt++;
                l++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};